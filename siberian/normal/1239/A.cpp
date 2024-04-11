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

int n, m;

void read() {
    cin >> n >> m;
}

const int MAXN = 2e5 + 10;
int dp[MAXN][2];
int ans = 0;

void run() {
    dp[1][0] = 1;
    for (int i = 2; i < MAXN; i++) {
        dp[i][0] = add(dp[i - 1][1], dp[i - 1][0]);
        dp[i][1] = dp[i - 1][0];
    } 
    /*cout << "dp = " << endl;
    for (int i = 1; i <= max(n, m); i++) {
        cout << dp[i][0] << " " << dp[i][1] << "\n";
    }*/
    ans = add(add(dp[n][0], dp[n][1]), add(dp[m][0], dp[m][1]));
    //cout << ans<< endl;
    ans = mul(ans, 2);
    ans = sub(ans, 2);
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