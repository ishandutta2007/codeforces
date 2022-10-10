#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int dp[75][75][75][75];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    // row, column, num taken, sum mod k
    memset(dp, 128, sizeof(dp));
    dp[0][0][0][0] = 0;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            int a;
            cin >> a;
            for (int take=0; take<=m/2; take++)
                for (int s=0; s<k; s++) {
                    dp[i][j+1][take][s] = max(dp[i][j+1][take][s], dp[i][j][take][s]);
                    dp[i][j+1][take+1][(s+a)%k] = max(dp[i][j+1][take+1][(s+a)%k], dp[i][j][take][s] + a);
                }
            if (j == m - 1) {
                for (int take=0; take<=m/2; take++)
                    for (int s=0; s<k; s++)
                        dp[i+1][0][0][s] = max(dp[i+1][0][0][s], dp[i][m][take][s]);
            }
        }
    int ret = 0;
    for (int take=0; take<=m/2; take++)
        ret = max(ret, dp[n][0][take][0]);
    cout << ret << "\n";

    return 0;
}