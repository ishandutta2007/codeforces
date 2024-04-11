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
    int gcd;
};

TNode *new_node(int L, int R) {
    return new TNode({L, R, nullptr, nullptr, 0});
}

int safe_gcd(TNode *root) {
    return (root ? root->gcd : 0);
}

void relax(TNode *root) {
    if (!root) {
        return;
    }
    root->gcd = __gcd(safe_gcd(root->left), safe_gcd(root->right));
}

vector <int> a;

TNode *build_tree(int L, int R) {
    TNode *root  = new_node(L, R);
    if (R - L == 1) {
        root->gcd = a[L];
    } else {
        int M = (L + R) / 2;
        root->left = build_tree(L, M);
        root->right = build_tree(M, R);
        relax(root);
    }
    return root;
}

void change(TNode *root, int p, int x) {
    if (root->L > p || root->R <= p) {
        return;
    }
    if (root->R - root->L == 1) {
        root->gcd = x;
        return;
    }
    change(root->left, p, x);
    change(root->right, p, x);
    relax(root);
}

bool fl = true;
int cnt = 0;

void force(TNode *root, int L, int R, int x) {
    if (root->L >= R || L >= root->R) {
        return;
    }
    if (L <= root->L && root->R <= R) {
        if (root->gcd % x == 0) return;
        if (root->R - root->L == 1) {
            cnt++;
            if (cnt == 2) {
                fl = false;
            }
            return;
        }
        if (cnt == 2 || (safe_gcd(root->left) % x && safe_gcd(root->right) % x)) {
            fl = false;
            return;
        }
    }
    force(root->left, L, R, x);
    if (!fl) {
        return;
    }
    force(root->right, L, R, x);
    if (!fl) {
        return;
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
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    TNode *root = build_tree(0, n);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int tp;
        cin >> tp;
        if (tp == 2) {
            int p, x;
            cin >> p >> x;
            p--;
            change(root, p, x);
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            l--, r--;
            fl = true;
            cnt = 0;
            force(root, l, r + 1, x);
            cout << (fl ? "YES" : "NO") << "\n";
        }
    }
}