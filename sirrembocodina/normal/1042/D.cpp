#include <bits/stdc++.h>

using namespace std;

#define int int64_t

vector<int> t;

void add_x(int v, int l, int r, int x) {
    t[v]++;
    if (l == r - 1) {
        return;
    }
    int mid = (l + r) / 2;
    if (x < mid) {
        add_x(2 * v + 1, l, mid, x);
    } else {
        add_x(2 * v + 2, mid, r, x);
    }
}

int get_sum(int v, int l, int r, int L, int R) {
    if (R <= l || r <= L) {
        return 0;
    }
    if (L <= l && r <= R) {
        return t[v];
    }
    int mid = (l + r) / 2;
    return get_sum(2 * v + 1, l, mid, L, R) +
           get_sum(2 * v + 2, mid, r, L, R);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n, T;
    cin >> n >> T;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> s(n + 1);
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + a[i];
    }
    n++;
    vector<int> b = s;
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        s[i] = lower_bound(b.begin(), b.end(), s[i]) - b.begin();
    }
    int tree_sz = 1;
    while (tree_sz < 2 * n) {
        tree_sz *= 2;
    }
    t.resize(tree_sz);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += get_sum(0, 0, n, upper_bound(b.begin(), b.end(), b[s[i]] - T) - b.begin(), n);
        add_x(0, 0, n, s[i]);
    }
    cout << ans;
}