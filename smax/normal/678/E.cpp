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

    int n;
    cin >> n;
    vector p(n, vector<double>(n));
    for (auto &v : p)
        for (auto &x : v)
            cin >> x;

    vector dp(1 << n, vector<double>(n));
    dp[1][0] = 1;
    for (int mask=3; mask<1<<n; mask++)
        for (int i=0; i<n; i++)
            if (mask >> i & 1)
                for (int j=0; j<n; j++)
                    if (i != j && mask >> j & 1)
                        dp[mask][i] = max(dp[mask][i], dp[mask^(1<<j)][i] * p[i][j] + dp[mask^(1<<i)][j] * p[j][i]);
    cout << fixed << setprecision(10) << *max_element(dp[(1<<n)-1].begin(), dp[(1<<n)-1].end()) << "\n";

    return 0;
}