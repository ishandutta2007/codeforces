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

const int MAXN = 5e3 + 10;
int n, a, b, k;

void read() {
    cin >> n >> a >> b >> k;
}

int dp[MAXN][MAXN];
int ans;

void build(int it) {
    for (int i = 1; i <= n; i++) {
        dp[it][i] = add(dp[it][i], dp[it][i - 1]);
    }
}

int get(int it, int l, int r) {
    if (l > r) return 0;
    return sub(dp[it][r], dp[it][l - 1]);
}

void run() {
    if (a > b) {
        a = n - a + 1;
        b = n - b + 1;
    } 
    n = b;

    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            dp[i][j] = 0;
    dp[0][a] = 1;
    for (int i = 1; i <= k; i++) {
        build(i - 1);
        for (int j = 1; j < n; j++) {
            dp[i][j] = get(i - 1, 1, (n + j - 1) / 2);
            dp[i][j] = sub(dp[i][j], get(i - 1, j, j));
            /*for (int last = 1; last <= (n + j - 1) / 2; last++) {
                if (j != last) {
                    dp[i][j] = add(dp[i][j], dp[i - 1][last]);
                }
            }*/
        }
    }

    ans = 0;
    for (int i = 1; i < n; i++) {
        ans = add(ans, dp[k][i]);
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