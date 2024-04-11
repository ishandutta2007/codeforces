#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

struct Node;

const int N = 1111111;

typedef pair<Node*, Node*> Pair;

struct Node {
    int size;
    Node *left, *right;
    int key;
    
    Node() {}
    
    Node(Node *left, Node *right, int k = 0) : left(left), right(right) {
        key = k;
    }
    
    Node *update() {
        size = left->size + right->size + 1;
        return this;
    }
    
    void show();
    Pair split(int);
};

Node Me[N];

int used = 0;

inline int randd() {
    static int x = 1;
    x += (x << 1) + 1;
    return x & 2147483647;
}

bool random(int a, int b) {
    return randd() % (a + b) < a;
}

Node *null;

Node *mergy(Node *p, Node *q) {
    if (p == null) {
        return q;
    }   
    
    if (q == null) {
        return p;
    }
    
    if (random(p->size, q->size)) {
        p->right = mergy(p->right, q);
        return p->update();
    }
    q->left = mergy(p, q->left);
    return q->update();
}

Pair Node :: split(int n) {
    if (this == null) {
        return make_pair(null, null);
    }
    
    if (n <= left->size) {
        Pair ret = left->split(n);
        left = null;
        return make_pair(ret.first, mergy(ret.second, this->update()));
    }
    Pair ret = right->split(n - left->size - 1);
    right = null;
    return make_pair(mergy(this->update(), ret.first), ret.second);
}

void Node :: show() {
    if (this == null)
        return;
    
    this->left->show();
    printf("%d", this->key);
    this->right->show();
}

int a[N];

Node* newNode(Node* a, Node *b, int k = 0) {
    Me[used] = Node(a, b, k);
    Me[used].size = 1;
    return &Me[used++];
}

int main() {
    
    null = newNode(0, 0);
    null->left = null->right = null;
    null->size = 0;
    
    int n, m, s = 0;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d", &a[i]);
    }
    
    Node *root = null;
    
    for(int i = 1; i <= n; i++) {
        int op;
        scanf("%d", &op);
        if (op >= 0) {
            root = mergy(root, newNode(null, null, op));
        } else {
            for(int j = 1; j <= m; j++) {
                if (a[j] - j + 1 > root->size)
                    break;
                Pair ret1 = root->split(a[j] - j);
                Pair ret2 = ret1.second->split(1);
                root = mergy(ret1.first, ret2.second); 
            }
        }
    }
    
    if (root->size == 0) {
        printf("Poor stack!\n");
    } else {
        root->show();
    }
    return 0;   
}