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

int dp[5005][5005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    string a, b;
    cin >> n >> m >> a >> b;

    int ret = 0;
    memset(dp, 128, sizeof(dp));
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) - 1;
            if (a[i-1] == b[j-1])
                dp[i][j] = max(dp[i][j], max(dp[i-1][j-1], 0) + 2);
            ret = max(ret, dp[i][j]);
        }
    cout << ret << "\n";

    return 0;
}