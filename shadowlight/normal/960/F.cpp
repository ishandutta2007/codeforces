#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

struct TNode {
    int x, y;
    TNode *left, *right;
    int val, maxk;
};

TNode *new_node(int x, int val) {
    return new TNode({x, rand(), nullptr, nullptr, val, val});
}

int safe_max(TNode *root) {
    return (root ? root->maxk : 0);
}

void relax(TNode *root) {
    if (!root) {
        return;
    }
    root->maxk = max({safe_max(root->left), safe_max(root->right), root->val});
}

TNode *merge(TNode *left, TNode *right) {
    if (!left) {
        return right;
    }
    if (!right) {
        return left;
    }
    if (left->y > right->y) {
        left->right = merge(left->right, right);
        relax(left);
        return left;
    } else {
        right->left = merge(left, right->left);
        relax(right);
        return right;
    }
}

pair <TNode*, TNode*> split(TNode *root, int x) {
    if (!root) {
        return {nullptr, nullptr};
    }
    if (root->x > x) {
        auto p = split(root->left, x);
        root->left = p.second;
        relax(root);
        return {p.first, root};
    } else {
        auto p = split(root->right, x);
        root->right = p.first;
        relax(root);
        return {root, p.second};
    }
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
    int n, m;
    cin >> n >> m;
    vector <TNode*> a(n, nullptr);
    for (int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        auto p = split(a[v], w - 1);
        int now = safe_max(p.first) + 1;
        a[v] = merge(p.first, p.second);
        auto p1 = split(a[u], w);
        a[u] = merge(p1.first, merge(new_node(w, now), p1.second));
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, safe_max(a[i]));
    }
    cout << res;
}