#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e5 + 7;
const double EPS = 1e-8;
const int LOGN = 30;

int timer = 0;

vector <int> a, on;
vector <int> tin, tout;
vector <vector <int> > gr;
int n;

void dfs(int v) {
    //cout << v << "\n";
    tin[v] = a.size();
    a.push_back(v);
    for (int u : gr[v]) {
        dfs(u);
    }
    tout[v] = a.size() - 1;
}

struct TNode {
    int L, R;
    TNode *left, *right;
    int sum;
    bool fl;
};

TNode *new_node(int L, int R) {
    return new TNode({L, R, nullptr, nullptr, 0});
}

int safe_sum(TNode *root) {
    if (!root) {
        return 0;
    }
    return root->sum;
}

void relax(TNode *root) {
    if (!root) return;
    root->sum = safe_sum(root->left) + safe_sum(root->right);
}

void add_val(TNode *root) {
    if (!root) return;
    root->sum = (root->R - root->L) - root->sum;
    root->fl ^= 1;
}

void push(TNode *root) {
    if (!root || !root->fl) return;
    add_val(root->left);
    add_val(root->right);
    root->fl = 0;
}

TNode *build_tree(int L, int R) {
    TNode *root = new_node(L, R);
    if (R - L == 1) {
        root->sum = on[a[L]];
    } else {
        int M = (L + R) / 2;
        root->left = build_tree(L, M);
        root->right = build_tree(M, R);
        relax(root);
    }
    return root;
}

int get_sum(TNode *root, int L, int R) {
    if (L >= root->R || root->L >= R) {
        return 0;
    }
    if (L <= root->L && root->R <= R) {
        return root->sum;
    }
    push(root);
    int sum = get_sum(root->left, L, R) + get_sum(root->right, L, R);
    relax(root);
    return sum;
}

void add_otr(TNode *root, int L, int R) {
    if (L >= root->R || root->L >= R) {
        return;
    }
    if (L <= root->L && root->R <= R) {
        add_val(root);
        return;
    }
    push(root);
    add_otr(root->left, L, R);
    add_otr(root->right, L, R);
    relax(root);
}


int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    cin >> n;
    tin.resize(n, 0);
    tout.resize(n, 0);
    on.resize(n, 0);
    gr.resize(n);
    for (int i = 1; i < n; i++) {
        int pr;
        cin >> pr;
        pr--;
        gr[pr].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> on[i];
    }
    dfs(0);
    //cout << "kek\n";
    TNode *root = build_tree(0, n);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string type;
        cin >> type;
        int v;
        cin >> v;
        v--;
        if (type == "pow") {
            add_otr(root, tin[v], tout[v] + 1);
        } else {
            //cout << v << " " << tin[v] << " " << tout[v] + 1 << "\n";
            cout << get_sum(root, tin[v], tout[v] + 1) << "\n";
        }
    }
}