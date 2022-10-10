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

    int n, l, k;
    cin >> n >> l >> k;
    vector<int> d(n), a(n);
    for (int i=0; i<n; i++)
        cin >> d[i];
    for (int i=0; i<n; i++)
        cin >> a[i];
    d.push_back(l);

    vector<vector<int>> dp(1, vector<int>(k + 1, 1e9 + 5));
    dp[0][0] = 0;
    for (int i=1; i<=n; i++) {
        vector<vector<int>> ndp(i + 1, vector<int>(k + 1, 1e9 + 5));
        for (int j=0; j<i; j++)
            for (int x=0; x<=k; x++) {
                ndp[i][x] = min(ndp[i][x], dp[j][x] + a[j] * (d[i] - d[i-1]));
                if (x < k)
                    ndp[j][x+1] = min(ndp[j][x+1], dp[j][x] + a[j] * (d[i] - d[i-1]));
            }
        dp.swap(ndp);
    }

    int ret = INT_MAX;
    for (int j=0; j<=n; j++)
        for (int x=0; x<=k; x++)
            ret = min(ret, dp[j][x]);
    cout << ret << "\n";

    return 0;
}