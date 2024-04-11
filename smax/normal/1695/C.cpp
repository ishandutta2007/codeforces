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

bitset<1000> dp[1000][1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector a(n, vector<int>(m));
        for (auto &v : a)
            for (int &x : v)
                cin >> x;

        if ((n + m - 1) % 2) {
            cout << "NO\n";
            continue;
        }

        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j][a[i][j]!=1] = 0;
                    dp[i][j][a[i][j]==1] = 1;
                } else {
                    if (i > 0 && j > 0) dp[i][j] = dp[i-1][j] | dp[i][j-1];
                    else if (i > 0) dp[i][j] = dp[i-1][j];
                    else if (j > 0) dp[i][j] = dp[i][j-1];
                    if (a[i][j] == 1) dp[i][j] <<= 1;
                }
            }
        cout << (dp[n-1][m-1][(n+m-1)/2] ? "YES" : "NO") << "\n";
    }

    return 0;
}