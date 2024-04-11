#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

vector<int> mn, mx;

void build_tree(int v, int l, int r, vector<int>& a) {
    if (l == r - 1) {
        mn[v] = mx[v] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build_tree(2 * v + 1, l, mid, a);
    build_tree(2 * v + 2, mid, r, a);
    mn[v] = min(mn[2 * v + 1], mn[2 * v + 2]);
    mx[v] = max(mx[2 * v + 1], mx[2 * v + 2]);
}

int get_min(int v, int l, int r, int L, int R) {
    if (r <= L || R <= l) {
        return 2e18;
    }
    if (L <= l && r <= R) {
        return mn[v];
    }
    int mid = (l + r) / 2;
    return min(
               get_min(2 * v + 1, l, mid, L, R),
               get_min(2 * v + 2, mid, r, L, R)
            );
}

int get_max(int v, int l, int r, int L, int R) {
    if (r <= L || R <= l) {
        return -2e18;
    }
    if (L <= l && r <= R) {
        return mx[v];
    }
    int mid = (l + r) / 2;
    return max(
               get_max(2 * v + 1, l, mid, L, R),
               get_max(2 * v + 2, mid, r, L, R)
            );
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int& x: a) {
        cin >> x;
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = x - a[i];
    }
    vector<int> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + a[i];
    }
    int tree_sz = 1;
    while (tree_sz < 2 * (n + 1)) {
        tree_sz *= 2;
    }
    mn.resize(tree_sz);
    mx.resize(tree_sz);
    build_tree(0, 0, n + 1, sum);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        if (sum[r] != sum[l] || get_min(0, 0, n + 1, l, r + 1) < sum[l]) {
            cout << -1 << '\n';
        } else {
            cout << get_max(0, 0, n + 1, l, r + 1) - sum[l] << '\n';
        }
    }
    return 0;
}