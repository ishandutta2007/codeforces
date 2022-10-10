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

// position, number of t[0] encountered, number of moves remaining
int dp[205][205][205];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k;
    string s, t;
    cin >> n >> k >> s >> t;

    if (t[0] == t[1]) {
        int cnt = 0;
        for (char c : s)
            cnt += (c == t[0]);
        int tot = cnt + min((int) s.length() - cnt, k);
        cout << tot * (tot - 1) / 2 << "\n";
    } else {
        memset(dp, 128, sizeof(dp));
        dp[0][0][0] = 0;
        for (int i=0; i<n; i++)
            for (int j=0; j<=i; j++)
                for (int l=0; l<=k; l++) {
                    // change to t[0]
                    if (l + (s[i] != t[0]) <= k)
                        dp[i+1][j+1][l+(s[i]!=t[0])] = max(dp[i+1][j+1][l+(s[i]!=t[0])], dp[i][j][l]);
                    // change to t[1]
                    if (l + (s[i] != t[1]) <= k)
                        dp[i+1][j][l+(s[i]!=t[1])] = max(dp[i+1][j][l+(s[i]!=t[1])], dp[i][j][l] + j);
                    // don't change at all
                    if (s[i] != t[0] && s[i] != t[1])
                        dp[i+1][j][l] = max(dp[i+1][j][l], dp[i][j][l]);
                }
        int ret = 0;
        for (int j=0; j<=n; j++)
            for (int l=0; l<=k; l++)
                ret = max(ret, dp[n][j][l]);
        cout << ret << "\n";
    }

    return 0;
}