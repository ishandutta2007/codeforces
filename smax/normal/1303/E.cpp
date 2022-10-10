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

    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        int n = s.size();
        for (int k=0; k<(int)t.size(); k++) {
            string a = t.substr(0, k + 1), b = t.substr(k + 1);
            int m = a.size(), o = b.size();
            // position, first subsequence, second subsequence
            vector<vector<int>> dp(n + 1, vector<int>(m + 1, -INF));
            dp[0][0] = 0;
            for (int i=0; i<n; i++)
                for (int j=0; j<=m; j++)
                    if (dp[i][j] >= 0) {
                        // skip character
                        dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
                        // add character to first subsequence
                        if (j < m && s[i] == a[j])
                            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
                        // add character to second subsequence
                        if (dp[i][j] < o && s[i] == b[dp[i][j]])
                            dp[i+1][j] = max(dp[i+1][j], dp[i][j] + 1);
                    }
            if (dp[n][m] == o) {
                cout << "YES\n";
                goto done;
            }
        }
        cout << "NO\n";
        done:;
    }

    return 0;
}