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

long double dp[1005][1005];
bool vis[1005][1005];

// probability current player wins, player has m cards and opponent has n
long double solve(int n, int m) {
    if (n == 0)
        return 1;
    if (m == 0)
        return 1.0L / (n + 1);
    if (vis[n][m])
        return dp[n][m];
    vis[n][m] = true;
    long double a = n * (1 - solve(m, n - 1)) / (n + 1);
    long double b = 1.0L / (n + 1) + n * (1 - solve(m, n - 1)) / (n + 1);
    long double c = 1;
    long double d = 1 - solve(m - 1, n);
    long double p = (d - b) / (a - b - c + d);
    long double q = (d - c) / (a - b - c + d);
    return dp[n][m] = max(1.0L / (n + 1), q * (p * a + (1 - p) * b) + (1 - q) * (p * c + (1 - p) * d));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;
    cout << fixed << setprecision(10) << solve(n, m) << " " << 1 - solve(n, m) << "\n";

    return 0;
}