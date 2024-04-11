#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

struct my_hash {
    inline size_t operator()(const pair<int, int>& a) const {
        return a.first * 31 + a.second;
    }
};

vector<int> t;

void set_elem(int v, int l, int r, int i, int x) {
    t[v] = max(t[v], x);
    if (l == r - 1) {
        return;
    }
    int mid = (l + r) / 2;
    if (i < mid) {
        set_elem(2 * v + 1, l, mid, i, x);
    } else {
        set_elem(2 * v + 2, mid, r, i, x);
    }
}

int get_max(int v, int l, int r, int L, int R) {
    if (r <= L || R <= l) {
        return -2e18;
    }
    if (L <= l && r <= R) {
        return t[v];
    }
    int mid = (l + r) / 2;
    return max(get_max(2 * v + 1, l, mid, L, R),
               get_max(2 * v + 2, mid, r, L, R));
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int tq = 1;
    cin >> tq;
    while (tq--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> sum(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + a[i];
        }

        vector<int> comp = sum;
        sort(comp.begin(), comp.end());
        for (int i = 0; i <= n; i++) {
            sum[i] = lower_bound(comp.begin(), comp.end(), sum[i]) - comp.begin();
        }

        int tree_sz = 1;
        while (tree_sz < 2 * (n + 1)) {
            tree_sz *= 2;
        }
        t.clear();
        t.assign(tree_sz, -2e18);

        vector<int> best_dp(n + 1, -2e18);

        vector<int> dp(n + 1);
        best_dp[sum[0]] = max(best_dp[sum[0]], dp[0]);
        set_elem(0, 0, n + 1, sum[0], dp[0] - 0);
        for (int i = 1; i <= n; i++) {
            dp[i] = max(max(dp[i - 1] - 1, best_dp[sum[i]]), get_max(0, 0, n + 1, 0, sum[i]) + i);
            best_dp[sum[i]] = max(best_dp[sum[i]], dp[i]);
            set_elem(0, 0, n + 1, sum[i], dp[i] - i);
        }
        cout << dp[n] << '\n';
    }
}