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

vector<int> t_sum, t_dif;

void add_x(int v, int l, int r, int i, int x) {
    t_sum[v] += x * i;
    t_dif[v] += x;
    if (l == r - 1) {
        return;
    }
    int mid = (l + r) / 2;
    if (i < mid) {
        add_x(2 * v + 1, l, mid, i, x);
    } else {
        add_x(2 * v + 2, mid, r, i, x);
    }
}

int get_sum(int v, int l, int r, int L, int R) {
    if (r <= L || R <= l) {
        return 0;
    }
    if (L <= l && r <= R) {
        return t_sum[v];
    }
    int mid = (l + r) / 2;
    return get_sum(2 * v + 1, l, mid, L, R) +
           get_sum(2 * v + 2, mid, r, L, R);
}

int get_dif(int v, int l, int r, int L, int R) {
    if (r <= L || R <= l) {
        return 0;
    }
    if (L <= l && r <= R) {
        return t_dif[v];
    }
    int mid = (l + r) / 2;
    return get_dif(2 * v + 1, l, mid, L, R) +
           get_dif(2 * v + 2, mid, r, L, R);
}

int32_t main() {
    srand(time(nullptr));
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a, b;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x < n) {
                a.push_back(x);
            } else {
                b.push_back(x);
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int cur = n;
        for (int i = 0; i < b.size(); i++) {
            if (i && b[i] != b[i - 1]) {
                cur++;
            }
            a.push_back(cur);
        }
        vector<int> cnt(2 * n);
        for (int i = 0; i < n; i++) {
            cnt[a[i]]++;
        }
        vector<int> sum(2 * n + 1);
        vector<int> dif(2 * n + 1);
        for (int i = 0; i < 2 * n; i++) {
            sum[i + 1] = sum[i] + cnt[i];
            dif[i + 1] = dif[i] + bool(cnt[i]);
        }

        int tree_sz = 1;
        while (tree_sz < 2 * n) {
            tree_sz *= 2;
        }
        t_dif.assign(tree_sz, 0);
        t_sum.assign(tree_sz, 0);
        for (int i = 0; i < 2 * n; i++) {
            if (cnt[i]) {
                add_x(0, 1, n + 1, cnt[i], 1);
            }
        }

        int ans = dif[2 * n];
        for (int i = 1; i <= n; i++) {
            if (i - dif[i] > k) {
                break;
            }
            if (cnt[i - 1]) {
                add_x(0, 1, n + 1, cnt[i - 1], -1);
            }
            int l = 1, r = n + 2;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (get_sum(0, 1, n + 1, 1, mid) <= k) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            int cur_ans = get_dif(0, 1, n + 1, l, n + 1);
            if (l < n + 1) {
                int rem = k - get_sum(0, 1, n + 1, 1, l);
                cur_ans -= rem / l;
            }
            ans = min(ans, cur_ans);
        }
        cout << ans << '\n';
    }
}