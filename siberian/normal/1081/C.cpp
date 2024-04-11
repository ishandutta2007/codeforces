#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MOD = 998244353;

int add(int a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0)
        a += MOD;
    return a;
}

int mul(int a, int b) {
    return (ll) a * b % MOD;
}

const int MAXN = 2010;
int n, m, k;

void read() {
    cin >> n >> m >> k;
}

int dp[MAXN][MAXN];
int ans;

void run() {
    dp[1][0] = m;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][0];
        for (int cnt = 1; cnt <= k; cnt++) {
            dp[i][cnt] = add(dp[i - 1][cnt], mul(dp[i - 1][cnt - 1], m - 1));
        }
    }
    ans = dp[n][k];
}

void write() {
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read();
    run();
    write();
    return 0;
}