#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MOD = 1e9 + 7;

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

int n, k;

void read() {
    cin >> n >> k;
}

const int MAXN = 2e3 + 10;
int dp[MAXN][MAXN];
int ans;

void run() {
    dp[0][1] = 1;
    for (int i = 0; i < k; i++) {
        for (int x = 1; x <= n; x++) {
            if (dp[i][x] == 0) continue;
            for (int fmul = 1; fmul * x <= n; fmul++) {
                dp[i + 1][x * fmul] = add(dp[i + 1][x * fmul], dp[i][x]);
            }
        }
    }
    ans = 0;
    for (int x = 1; x <= n; x++) {
        ans = add(ans, dp[k][x]);
    }
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