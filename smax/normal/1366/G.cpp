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

int nxt[10005], dp[10005][10005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();

    for (int i=0; i<n; i++) {
        nxt[i] = -1;
        if (s[i] != '.') {
            int cnt = 0;
            for (int j=i; j<n; j++) {
                cnt += (s[j] == '.' ? -1 : 1);
                if (cnt == 0) {
                    nxt[i] = j;
                    break;
                }
            }
        }
    }

    memset(dp, 127, sizeof(dp));
    dp[0][0] = 0;
    for (int i=0; i<n; i++)
        for (int j=0; j<=m; j++) {
            // erase the character
            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1);
            // process the character if dot
            if (s[i] == '.' && j > 0)
                dp[i+1][j-1] = min(dp[i+1][j-1], dp[i][j]);
            // process the character if match
            if (j < m && s[i] == t[j])
                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
            // append wrong character with intention of deleting later
            if (nxt[i] != -1)
                dp[nxt[i]+1][j] = min(dp[nxt[i]+1][j], dp[i][j]);
        }
    cout << dp[n][m] << "\n";

    return 0;
}