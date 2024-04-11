#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

struct TNode {
    int L, R;
    TNode *left, *right;
    int min, max;
};

vector <int> a;

TNode *new_node(int L, int R) {
    return new TNode({L, R, nullptr, nullptr, 0, 0});
}

int safe_min(TNode *root) {
    return (root ? root->min : INF);
}

int safe_max(TNode *root) {
    return (root ? root->max : -INF);
}

int safe_size(TNode *root) {
    return (root ? root->R - root->L : 0);
}

void relax(TNode *root) {
    if (!root) {
        return;
    }
    root->max = max(safe_max(root->left), safe_max(root->right));
    root->min = min(safe_min(root->left), safe_min(root->right));
}

TNode *build_tree(int L, int R) {
    TNode *root = new_node(L, R);
    if (R - L == 1) {
        root->min = a[L];
        root->max = a[L];
    } else {
        int M = (L + R) / 2;
        root->left = build_tree(L, M);
        root->right = build_tree(M, R);
        relax(root);
    }
    return root;
}

int get(TNode *root, int L, int mink, int maxk) {
    //cout << root->L << " " << root->R << "\n";
    if (root->R <= L) {
        return 0;
    }
    if (root->L < L) {
        int x = get(root->left, L, mink, maxk);
        if (x == max(root->left->R - L, 0)) {
            return x + get(root->right, L, mink, maxk);
        }
        return x;
    }
    if (root->R - root->L == 1) {
        return (root->min >= mink && root->max <= maxk);
    }
    if (safe_min(root->left) >= mink && safe_max(root->left) <= maxk) {
        return safe_size(root->left) + get(root->right, L, mink, maxk);
    }
    return get(root->left, L, mink, maxk);
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
    int n;
    cin >> n;
    a.resize(n + 2);
    cin >> a[0] >> a[1];
    for (int i = 0; i < n; i++) {
        cin >> a[i + 2];
    }
    TNode *root = build_tree(0, n + 2);
    int lp = 0, rp = INF;
    //cout << get(root, 2, 3, 5) << "\n";
    while (rp - lp > 1) {
        int p = (lp + rp) / 2;
        int r = 0;
        for (int i = 0; i < n + 1; i++) {
            if (i > r) break;
            if (abs(a[i] - a[i + 1]) > p) continue;
            int r1 = i + get(root, i, a[i] - p, a[i] + p) - 1;
            int r2 = i + get(root, i, a[i + 1] - p, a[i + 1] + p) - 1;
//            if (p == 3) {
//                cout << i << " " << r1 << " " << r2 << "\n";
//            }
            r = max({r, r1, r2});
        }
        if (r == n + 1) {
            rp = p;
        } else {
            lp = p;
        }
    }
    cout << rp;
}