#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i=1; i<=n; i++)
        cin >> a[i];

    vector<int> nxt(n + 1), last(2, n + 1);
    for (int i=n; i>0; i--) {
        nxt[i] = last[a[i]];
        last[a[i]] = i;
    }

    // position, last unoccupied chair/last unmatched person
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, n * n));
    dp[0][0] = 0;
    for (int i=1; i<=n; i++)
        for (int j=0; j<i; j++) {
            if (a[i]) {
                if (j == 0) {
                    // now last unmatched person
                    dp[i][i] = min(dp[i][i], dp[i-1][j]);
                } else if (a[j]) {
                    // still same last unmatched person
                    dp[i][j] = min(dp[i][j], dp[i-1][j]);
                } else {
                    // occupy the chair
                    dp[i][nxt[j] < i ? nxt[j] : 0] = min(dp[i][nxt[j] < i ? nxt[j] : 0], dp[i-1][j] + i - j);
                    // consider next unoccupied chair
                    if (nxt[j] < i)
                        dp[i-1][nxt[j]] = min(dp[i-1][nxt[j]], dp[i-1][j]);
                    // skip all unoccupied chairs behind, match forward instead
                    dp[i][i] = min(dp[i][i], dp[i-1][j]);
                }
            } else {
                if (j == 0) {
                    // now last unoccupied chair
                    dp[i][i] = min(dp[i][i], dp[i-1][j]);
                } else if (a[j]) {
                    // occupy this chair
                    dp[i][nxt[j] < i ? nxt[j] : 0] = min(dp[i][nxt[j] < i ? nxt[j] : 0], dp[i-1][j] + i - j);
                    // skip this chair
                    dp[i][j] = min(dp[i][j], dp[i-1][j]);
                } else {
                    // still same last unoccupied chair
                    dp[i][j] = min(dp[i][j], dp[i-1][j]);
                }
            }
        }

    int ret = n * n;
    for (int j=0; j<=n; j++)
        if (a[j] == 0)
            ret = min(ret, dp[n][j]);
    cout << ret << "\n";

    return 0;
}