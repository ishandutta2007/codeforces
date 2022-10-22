#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e5 + 7;
const double EPS = 1e-8;

struct TNode {
    int L, R;
    TNode *left, *right;
    int x;
};

TNode *new_node(int L, int R) {
    return new TNode({L, R, nullptr, nullptr, INF});
}

TNode *build_tree(int L, int R) {
    TNode *root = new_node(L, R);
    if (R - L > 1) {
        int M = (L + R) / 2;
        root->left = build_tree(L, M);
        root->right = build_tree(M, R);
    }
    return root;
}

TNode *change(TNode *root, int p, int x) {
    if (root->L > p || root->R <= p) {
        return root;
    }
    TNode *node = new_node(root->L, root->R);
    if (root->R - root->L == 1) {
        node->x = x;
        return node;
    }
    node->left = change(root->left, p, x);
    node->right = change(root->right, p, x);
    return node;
}

int get(TNode *root, int p) {
    if (root->L > p || root->R <= p) {
        return -1;
    }
    if (root->R - root->L == 1) {
        return root->x;
    }
    return max(get(root->left, p), get(root->right, p));
}

struct Tree {
    int L, R;
    Tree *left, *right;
    int sum;
};

Tree *new_tree(int L, int R) {
    return new Tree({L, R, nullptr, nullptr, 0});
}

int safe_sum(Tree *root) {
    return (root ? root->sum : 0);
}

void relax(Tree *root) {
    if (!root) {
        return;
    }
    root->sum = safe_sum(root->left) + safe_sum(root->right);
}

Tree *add(Tree *root, int p, int x, int L = 0, int R = INF) {
    if (!root) {
        root = new_tree(L, R);
    }
    if (root->L > p || root->R <= p) {
        return root;
    }
    Tree *node = new_tree(root->L, root->R);
    if (node->R - node->L == 1) {
        node->sum = root->sum + x;
        return node;
    }
    int M = (L + R) / 2;
    node->left = add(root->left, p, x, L, M);
    node->right = add(root->right, p, x, M, R);
    relax(node);
    return node;
}

int get_sum(Tree *root, int L, int R) {
    if (!root || root->L >= R || L >= root->R) {
        return 0;
    }
    if (L <= root->L && root->R <= R) {
        return root->sum;
    }
    return get_sum(root->left, L, R) + get_sum(root->right, L, R);
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    map <string, int> id;
    vector <TNode*> ver1(1, build_tree(0, MAXN));
    vector <Tree*> ver2(1, new_tree(0, INF));
    int last = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string type;
        cin >> type;
        string name;
        if (type == "undo") {
            int d;
            cin >> d;
            ver1.push_back(ver1[i - d]);
            ver2.push_back(ver2[i - d]);
            continue;
        }
        cin >> name;
        if (!id.count(name)) {
            id[name] = last;
            last++;
        }
        if (type == "set") {
            int x;
            cin >> x;
            int px = get(ver1.back(), id[name]);
            ver1.push_back(change(ver1.back(), id[name], x));
            Tree *root = ver2.back();
            auto p1 = add(root, px, -1);
            p1 = add(p1, x, 1);
            //cout << "kek " << get_sum(p1, 0, INF) << "\n";
            ver2.push_back(p1);
        } else if (type == "remove") {
            int x = get(ver1.back(), id[name]);
            ver2.push_back(add(ver2.back(), x, -1));
            ver1.push_back(change(ver1.back(), id[name], INF));
        } else if (type == "query") {
            int x = get(ver1.back(), id[name]);
            if (x == INF) {
                cout << -1 << endl;
            } else {
                cout << get_sum(ver2.back(), 0, x) << endl;
            }
            ver1.push_back(ver1.back());
            ver2.push_back(ver2.back());
        }
    }

}