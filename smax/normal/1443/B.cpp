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

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        string s;
        cin >> a >> b >> s;
        int n = s.size();

        vector<vector<int>> dp(n + 1, vector<int>(2, INF));
        dp[0][0] = 0;
        for (int i=0; i<n; i++)
            for (int j=0; j<2; j++) {
                if (s[i] == '0') {
                    // continue without placing bomb
                    dp[i+1][0] = min(dp[i+1][0], dp[i][j]);
                    // place bomb, continue/start interval
                    dp[i+1][0] = min(dp[i+1][0], dp[i][j] + (j == 0 ? a : 0) + b);
                    dp[i+1][1] = min(dp[i+1][1], dp[i][j] + (j == 0 ? a : 0) + b);
                } else {
                    // continue/start interval
                    dp[i+1][0] = min(dp[i+1][0], dp[i][j] + (j == 0 ? a : 0));
                    dp[i+1][1] = min(dp[i+1][1], dp[i][j] + (j == 0 ? a : 0));
                }
            }
        cout << *min_element(dp[n].begin(), dp[n].end()) << "\n";
    }

    return 0;
}