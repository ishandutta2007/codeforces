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
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];

    vector<vector<long long>> dp(n + 1);
    dp[n] = {0};

    auto dfs = [&] (auto &self, int l, int r) -> int {
        if (l > r)
            return n;
        int u = l;
        for (int i=l+1; i<=r; i++)
            if (a[i] < a[u])
                u = i;
        int v = self(self, l, u - 1), w = self(self, u + 1, r);
        dp[u].resize(min((int) dp[v].size() + (int) dp[w].size(), m + 1), -1e18);
        for (int i=0; i<(int)dp[v].size(); i++)
            for (int j=0; j<(int)dp[w].size() && i+j<(int)dp[u].size(); j++) {
                dp[u][i+j] = max(dp[u][i+j], dp[v][i] + dp[w][j] - (long long) a[u] * 2 * i * j);
                if (i + j + 1 < (int) dp[u].size())
                    dp[u][i+j+1] = max(dp[u][i+j+1], dp[v][i] + dp[w][j] + (long long) a[u] * (m - 2 * (i + 1) * (j + 1) + 1));
            }
        return u;
    };

    cout << dp[dfs(dfs, 0, n - 1)][m] << "\n";

    return 0;
}