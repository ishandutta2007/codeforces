
#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define sqr(x) (x) * (x)

using namespace std;

const int mod = 998244353;

int dp[40][1 << 15];

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    forn (i, n) {
        cin >> a[i];
    }
    vector<int> good, bad;
    int cur = 0;
    forn (i, n) {
        if (cur == m) {
            break;
        }
        if ((a[i] & (1LL << cur)) == 0) {
            for (int j = i + 1; j < n; ++j) {
                if (a[j] & (1LL << cur)) {
                    swap(a[i], a[j]);
                    break;
                }
            }
        }
        if ((a[i] & (1LL << cur)) == 0) {
            bad.push_back(cur);
            cur++;
            --i;
            continue;
        }
        good.push_back(cur);
        for (int j = 0; j < n; ++j) {
            if (i != j && (a[j] & (1LL << cur))) {
                a[j] ^= a[i];
            }
        }
        cur++;
    }
    while (cur < m) {
        bad.push_back(cur);
        cur++;
    }
    forn (i, n) {
        //cout << a[i] << endl;
    }
    int rest = n - good.size();
    n = good.size();
    vector<int> ans(m + 1);
    if (n <= 20) {
        forn (mask, 1 << n) {
            int res = 0;
            forn (i, n) {
                if (mask & (1 << i)) {
                    res ^= a[i];
                }
            }
            ans[__builtin_popcountll(res)]++;
        }
    } else {
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            forn (j, bad.size()) {
                if (a[i] & (1LL << bad[j])) {
                    b[i] += 1LL << j;
                }
            }
        }
        dp[0][0] = 1;
        forn (i, n) {
            for (int j = i; j >= 0; --j) {
                forn (res, 1 << 15) {
                    dp[j + 1][res ^ b[i]] += dp[j][res];
                }
            }
        }
        forn (i, n + 1) {
            forn (res, 1 << 15) {
                if (dp[i][res]) {
                    ans[__builtin_popcountll(res) + i] += dp[i][res];
                }
            }
        }
    }
    forn (j, m + 1) {
        forn (i, rest) {
            ans[j] *= 2;
            ans[j] %= mod;
        }
        cout << ans[j] << ' ';
    }
    cout << endl;
}