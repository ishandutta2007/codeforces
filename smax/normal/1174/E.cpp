#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

#define MOD 1000000007

int n, dp[1000000][20][2] = {};

void add(int &a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}

int f(int j, int k) {
    int num = 1 << j;
    if (k > 0) num *= 3;
    return n / num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;

    int x = 31 - __builtin_clz(n);
    dp[0][x][0] = 1;
    if ((1 << (x - 1)) * 3 <= n)
        dp[0][x-1][1] = 1;
    for (int i=0; i<n-1; i++)
        for (int j=0; j<=x; j++)
            for (int k=0; k<2; k++) {
                add(dp[i+1][j][k], (long long) dp[i][j][k] * (f(j, k) - i - 1) % MOD);
                if (j > 0) add(dp[i+1][j-1][k], (long long) dp[i][j][k] * (f(j-1, k) - f(j, k)) % MOD);
                if (k > 0) add(dp[i+1][j][k-1], (long long) dp[i][j][k] * (f(j, k-1) - f(j, k)) % MOD);
            }

    cout << dp[n-1][0][0] << "\n";

    return 0;
}