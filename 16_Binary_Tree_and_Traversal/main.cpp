//
//  main.cpp
//  16_Binary_Tree_and_Traversal
//
//  Created by 세광 on 2021/08/16.
//

#include <iostream>

using namespace std;

int number = 15;

// 하나의 노드 정보 선언
typedef struct node *treePointer;
typedef struct node {
    int data;
    treePointer leftChild, rightChild;
} node;

// 전위 순회 구현
void Preorder(treePointer ptr) {
    if (ptr) {
        cout << ptr->data << ' ';
        Preorder(ptr->leftChild);
        Preorder(ptr->rightChild);
    }
}

// 중위 순회 구현
void Inorder(treePointer ptr) {
    if (ptr) {
        Inorder(ptr->leftChild);
        cout << ptr->data << ' ';
        Inorder(ptr->rightChild);
    }
}

// 후위 순회 구현
void Postorder(treePointer ptr) {
    if (ptr) {
        Postorder(ptr->leftChild);
        Postorder(ptr->rightChild);
        cout << ptr->data << ' ';
    }
}

int main() {
    node nodes[number + 1];
    for (int i = 1; i <= number; i++) {
        nodes[i].data = i;
        nodes[i].leftChild = NULL;
        nodes[i].rightChild = NULL;
    }
    
    for (int i = 1; i <= number; i++) {
        if (i % 2 == 0) nodes[i / 2].leftChild = &nodes[i];
        else nodes[i / 2].rightChild = &nodes[i];
    }
    
    cout << "Preorder Traversal: ";
    Preorder(&nodes[1]);
    cout << endl << "Inorder Traversal: ";
    Inorder(&nodes[1]);
    cout << endl << "Postorder Traversal: ";
    Postorder(&nodes[1]);
    cout << endl;
    return 0;
}
