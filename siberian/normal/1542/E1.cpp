#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

const int N = 51;

int MOD;


int c[N][N];
int fact[N];

int dp[N][N * N];


int add(int a, int b) {
    a += b;
    if (a >= MOD) return a - MOD;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0) return a + MOD;
    return a;
}

int mul(int a, int b) {
    return (ll)a * b % MOD;
}

int n;

int calc(vector<int>& order) {
    int ans = 0;
    for (int i = 0; i < order.size(); ++i) {
        for (int j = i + 1; j < order.size(); ++j) {
            if (order[i] > order[j]) {
                ++ans;
            }
        }
    }
    return ans;
}

int smartGet(int n, int cnt) {
    // return cnk(n * (n - 1) / 2, cnt);
    return dp[n][cnt];
}

int prefDp[N][N * N];

int get(int n, int cntInversions) {
    // vector<int> order(n);
    // iota(all(order), 0);
    // int ans = 0;
    // do {
    //     ans += calc(order) == cntInversions;
    // } while (next_permutation(all(order)));
    // return ans;
    // return smartGet(n, cntInversions);
    return dp[n][cntInversions];
}

int get(int n, int l, int r) {
    // int ans = 0;
    // for (int i = l; i <= r; ++i) {
    //     ans = add(ans, get(n, i));
    // }
    // return ans;
    return sub(prefDp[n][r], l > 0 ? prefDp[n][l - 1] : 0);
}

void precalc() {
    for (int i = 0; i < N; ++i) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
        }
    }
    fact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = mul(i, fact[i - 1]);
    }
    dp[0][0] = 1;
    for (int pref = 0; pref + 1 < N; ++pref) {
        for (int cnt = 0; cnt <= pref * (pref - 1) / 2; ++cnt) {
            for (int nxtAdd = 0; nxtAdd <= pref; ++nxtAdd) {
                dp[pref + 1][cnt + nxtAdd] = add(dp[pref + 1][cnt + nxtAdd], dp[pref][cnt]);
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N * N; ++j) {
            prefDp[i][j] = dp[i][j];
            if (j > 0) prefDp[i][j] = add(prefDp[i][j], prefDp[i][j - 1]);
        }
    }
}

int cnk(int n, int k) {
    if (n < k || k < 0) return 0;
    return c[n][k];
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n >> MOD;
    precalc();

    // for (int n = 0; n <= 4; ++n) {
    //     for (int cntInversions = 0; cntInversions <= n * (n - 1) / 2; ++cntInversions) {
    //         cerr << "n = " << n << " cnt = " << cntInversions << " get = " << get(n, cntInversions) << " " << smartGet(n, cntInversions) << endl;
    //     }
    // }

    // exit(0);

    int ans = 0;
    for (int len = 0; len < n; ++len) {
        int cntPref = mul(cnk(n, len), fact[len]);
        int fans = 0;
        int suff = n - len - 1;
        // q
        for (int val1 = 0; val1 < n - len; ++val1) {
            // p
            for (int val2 = 0; val2 < val1; ++val2) {
                int diff = val1 - val2;
                for (int cntQ = 0; cntQ <= suff * (suff - 1) / 2; ++cntQ) {
                    // int q = get(suff, cntQ);
                    // int p = get(suff, cntQ + diff + 1, suff * (suff - 1) / 2);
                    // cerr << "val1 = " << val1 << " val2 = " << val2 << " diff = " << diff << " cntQ = " << cntQ << " p = " << p << " q = " << q << endl; 
                    fans = add(fans, mul(get(suff, cntQ), get(suff, cntQ + diff + 1, suff * (suff - 1) / 2)));
                }       
            }
        }
        // for (int diff = 1; diff < n - len; ++diff) {
        //     int fDiff = 0;
        //     for (int cntQ = 0; cntQ <= suff * (suff - 1) / 2; ++cntQ) {
        //         fDiff = add(fDiff, mul(get(suff, cntQ), get(suff, cntQ + diff + 1, suff * (suff - 1) / 2)));
        //     }
        // }
        // cerr << "len = " << len << " cntPref = " << cntPref << " fans = " << fans << endl;
        ans = add(ans, mul(cntPref, fans));
        // 
        // break;
    }
    cout << ans << endl;
    return 0;
}