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
    double sum;
    double mul, add;
};

TNode *new_node(int L, int R) {
    return new TNode({L, R, nullptr, nullptr, 0, 1, 0});
}

vector <double> a;

double safe_sum(TNode *root) {
    if (!root) {
        return 0;
    }
    return root->sum;
}

void relax(TNode *root) {
    if (!root) {
        return;
    }
    root->sum = safe_sum(root->left) + safe_sum(root->right);
}

void add_val(TNode *root, double mul, double add) {
    if (!root) {
        return;
    }
    root->sum *= mul;
    root->sum += add * (root->R - root->L);
    root->mul *= mul;
    root->add = root->add * mul + add;
}

void push(TNode *root) {
    if (!root) {
        return;
    }
    add_val(root->left, root->mul, root->add);
    add_val(root->right, root->mul, root->add);
    root->mul = 1;
    root->add = 0;
}

TNode *build_tree(int L, int R) {
    TNode *root = new_node(L, R);
    if (R - L == 1) {
        root->sum = a[L];
    } else {
        int M = (L + R) / 2;
        root->left = build_tree(L, M);
        root->right = build_tree(M, R);
        relax(root);
    }
    return root;
}

double get_sum(TNode *root, int L, int R) {
    if (root->L >= R || L >= root->R) {
        return 0;
    }
    if (L <= root->L && root->R <= R) {
        return root->sum;
    }
    push(root);
    double sum = get_sum(root->left, L, R) + get_sum(root->right, L, R);
    relax(root);
    return sum;
}

void add_seg(TNode *root, int L, int R, double mul, double add) {
    if (root->L >= R || L >= root->R) {
        return;
    }
    if (L <= root->L && root->R <= R) {
        add_val(root, mul, add);
        return;
    }
    push(root);
    add_seg(root->left, L, R, mul, add);
    add_seg(root->right, L, R, mul, add);
    relax(root);
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
    int n, q;
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    TNode *root = build_tree(0, n);
    cout << fixed << setprecision(10);
    for (int i = 0; i < q; i++) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;
            l1--, l2--, r1--, r2--;
            double sz1 = r1 - l1 + 1, sz2 = r2 - l2 + 1;
            double sum1 = get_sum(root, l1, r1 + 1), sum2 = get_sum(root, l2, r2 + 1);
            //cout << (sz1 - 1) / sz1 << " " << sum2 / sz1 / sz2 << "\n";
            add_seg(root, l1, r1 + 1, (sz1 - 1) / sz1, sum2 / sz1 / sz2);
            add_seg(root, l2, r2 + 1, (sz2 - 1) / sz2, sum1 / sz1 / sz2);
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << get_sum(root, l, r + 1) << "\n";
        }
    }
}