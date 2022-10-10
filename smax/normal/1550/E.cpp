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

    int n, k;
    string s;
    cin >> n >> k >> s;

    auto check = [&] (int x) -> bool {
        vector<vector<int>> nxt(n, vector<int>(k, n + 1));
        vector<int> len(k);
        for (int i=0; i<n; i++)
            for (int j=0; j<k; j++) {
                if (s[i] == '?' || s[i] == j + 'a')
                    len[j]++;
                else
                    len[j] = 0;
                if (len[j] == x) {
                    nxt[i-x+1][j] = i + 1;
                    len[j]--;
                }
            }
        for (int i=n-2; i>=0; i--)
            for (int j=0; j<k; j++)
                nxt[i][j] = min(nxt[i][j], nxt[i+1][j]);

        vector<int> dp(1 << k, n + 1);
        dp[0] = 0;
        for (int mask=0; mask<1<<k; mask++)
            if (dp[mask] < n)
                for (int j=0; j<k; j++)
                    if (~mask & (1 << j))
                        dp[mask | (1 << j)] = min(dp[mask | (1 << j)], nxt[dp[mask]][j]);
        return dp[(1 << k) - 1] <= n;
    };

    int l = 1, r = n + 1;
    while (l < r) {
        int m = (l + r) / 2;
        if (check(m))
            l = m + 1;
        else
            r = m;
    }
    cout << l - 1 << "\n";

    return 0;
}