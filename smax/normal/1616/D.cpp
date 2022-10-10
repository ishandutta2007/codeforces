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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++)
            cin >> a[i];
        int x;
        cin >> x;

        vector<vector<int>> dp(n + 1, vector<int>(4, -1e9));
        dp[0][0] = 0;
        for (int i=0; i<n; i++)
            for (int mask=0; mask<4; mask++)
                if (dp[i][mask] >= 0) {
                    int nmask = (mask << 1) & 3;
                    dp[i+1][nmask] = max(dp[i+1][nmask], dp[i][mask]);
                    if ((~mask & 1 || a[i] + a[i-1] >= x * 2) && (~mask & 3 || a[i] + a[i-1] + a[i-2] >= x * 3))
                        dp[i+1][nmask|1] = max(dp[i+1][nmask|1], dp[i][mask] + 1);
                }
        cout << *max_element(dp[n].begin(), dp[n].end()) << "\n";
    }

    return 0;
}