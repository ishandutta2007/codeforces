#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

#define MAXN 2005

const int INF = 1e9;

int dp[MAXN][MAXN], cntS[MAXN][26], cntT[MAXN][26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    while (T--) {
        int n;
        string s, t;
        cin >> n >> s >> t;

        for (int j=0; j<26; j++)
            cntS[n+1][j] = cntT[n+1][j] = 0;
        for (int i=n; i>0; i--)
            for (int j=0; j<26; j++) {
                cntS[i][j] = cntS[i+1][j] + (s[i-1] - 'a' == j);
                cntT[i][j] = cntT[i+1][j] + (t[i-1] - 'a' == j);
            }

        for (int i=0; i<=n; i++)
            dp[i][0] = 0;
        for (int i=0; i<=n; i++)
            for (int j=1; j<=n; j++) {
                dp[i][j] = INF;
                int x = t[j-1] - 'a';
                if (cntS[i+1][x] > cntT[j+1][x])
                    dp[i][j] = min(dp[i][j], dp[i][j-1]);
                if (i > 0) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
                    if (s[i-1] == t[j-1])
                        dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                }
            }

        cout << (dp[n][n] >= INF ? -1 : dp[n][n]) << "\n";
    }

    return 0;
}