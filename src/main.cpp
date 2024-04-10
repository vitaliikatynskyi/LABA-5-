// #include <iostream> // Подключение библиотеки для работы с вводом-выводом
// #include <queue> // Подключение библиотеки для работы с очередью

// // Определение структуры узла дерева
// struct Node {
//     int data; // Данные, хранящиеся в узле
//     Node* left; // Указатель на левого потомка
//     Node* right; // Указатель на правого потомка
// };

// // Функция создания нового узла
// Node* createNode(int data) {
//     Node* newNode = new Node(); // Создание нового узла
//     if (!newNode) { // Если не удалось выделить память
//         std::cout << "Memory error\n"; // Вывод сообщения об ошибке
//         return nullptr; // Возвращение нулевого указателя
//     }
//     newNode->data = data; // Присваивание данных новому узлу
//     newNode->left = newNode->right = nullptr; // Оба потомка пока что отсутствуют
//     return newNode; // Возвращение указателя на новый узел
// }

// // Функция вставки нового узла в дерево
// Node* insertNode(Node* root, int data) {
//     if (root == nullptr) { // Если дерево пусто
//         root = createNode(data); // Создание корневого узла
//         return root; // Возвращение указателя на корень
//     }
//     std::queue<Node*> q; // Создание очереди для обхода дерева
//     q.push(root); // Добавление корня в очередь

//     // Пока очередь не пуста
//     while (!q.empty()) {
//         Node* temp = q.front(); // Получение первого узла из очереди
//         q.pop(); // Удаление этого узла из очереди

//         if (temp->left != nullptr) // Если у узла есть левый потомок
//             q.push(temp->left); // Добавление левого потомка в очередь
//         else { // Если у узла нет левого потомка
//             temp->left = createNode(data); // Создание левого потомка
//             return root; // Возвращение указателя на корень
//         }

//         if (temp->right != nullptr) // Если у узла есть правый потомок
//             q.push(temp->right); // Добавление правого потомка в очередь
//         else { // Если у узла нет правого потомка
//             temp->right = createNode(data); // Создание правого потомка
//             return root; // Возвращение указателя на корень
//         }
//     }
//     return root; // Возвращение указателя на корень
// }

// // Функция поиска максимального элемента в дереве
// int findMaxElement(Node* root) {
//     if (root == nullptr) { // Если дерево пусто
//         std::cout << "Tree is empty\n"; // Вывод сообщения об ошибке
//         return INT_MIN; // Возвращение минимально возможного значения
//     }
//     int maxElement = root->data; // Инициализация максимального элемента значением корня
//     std::queue<Node*> q; // Создание очереди для обхода дерева
//     q.push(root); // Добавление корня в очередь

//     // Пока очередь не пуста
//     while (!q.empty()) {
//         Node* temp = q.front(); // Получение первого узла из очереди
//         q.pop(); // Удаление этого узла из очереди

//         if (temp->data > maxElement) // Если значение узла больше текущего максимума
//             maxElement = temp->data; // Обновление максимума

//         if (temp->left != nullptr) // Если у узла есть левый потомок
//             q.push(temp->left); // Добавление левого потомка в очередь

//         if (temp->right != nullptr) // Если у узла есть правый потомок
//             q.push(temp->right); // Добавление правого потомка в очередь
//     }
//     return maxElement; // Возвращение максимального элемента
// }

// // Главная функция
// int main() {
//     Node* root = nullptr; // Создание пустого дерева
//     root = insertNode(root, 10); // Вставка узла со значением 10
//     root = insertNode(root, 20); // Вставка узла со значением 20
//     root = insertNode(root, 30); // Вставка узла со значением 30
//     root = insertNode(root, 40); // Вставка узла со значением 40
//     root = insertNode(root, 50); // Вставка узла со значением 50

//     int maxElement = findMaxElement(root); // Поиск максимального элемента в дереве
//     std::cout << "Maximum element in the tree: " << maxElement << "\n"; // Вывод максимального элемента

//     return 0; // Завершение работы программы
// }
#include <iostream>
#include <queue>

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        std::cout << "Memory error\n";
        return nullptr;
    }
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == nullptr) {
        root = createNode(data);
        return root;
    }
    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left != nullptr)
            q.push(temp->left);
        else {
            temp->left = createNode(data);
            return root;
        }

        if (temp->right != nullptr)
            q.push(temp->right);
        else {
            temp->right = createNode(data);
            return root;
        }
    }
    return root;
}

int findMaxElement(Node* root) {
    if (root == nullptr) {
        std::cout << "Tree is empty\n";
        return INT_MIN;
    }
    int maxElement = root->data;
    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->data > maxElement)
            maxElement = temp->data;

        if (temp->left != nullptr)
            q.push(temp->left);

        if (temp->right != nullptr)
            q.push(temp->right);
    }
    return maxElement;
}

int main() {
    Node* root = nullptr;
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);

    int maxElement = findMaxElement(root);
    std::cout << "Maximum element in the tree: " << maxElement << "\n";

    return 0;
}
