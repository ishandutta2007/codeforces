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
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> hori(n, vector<int>(m-1)), vert(n-1, vector<int>(m));
    for (int i=0; i<n; i++)
        for (int j=0; j<m-1; j++)
            cin >> hori[i][j];
    for (int i=0; i<n-1; i++)
        for (int j=0; j<m; j++)
            cin >> vert[i][j];

    if (k % 2) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++)
                cout << "-1 ";
            cout << "\n";
        }
        return 0;
    }

    k /= 2;
    vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(n, vector<int>(m, 1e9)));
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            dp[0][i][j] = 0;
    for (int l=0; l<k; l++)
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++) {
                if (i > 0)
                    dp[l+1][i-1][j] = min(dp[l+1][i-1][j], dp[l][i][j] + vert[i-1][j]);
                if (i + 1 < n)
                    dp[l+1][i+1][j] = min(dp[l+1][i+1][j], dp[l][i][j] + vert[i][j]);
                if (j > 0)
                    dp[l+1][i][j-1] = min(dp[l+1][i][j-1], dp[l][i][j] + hori[i][j-1]);
                if (j + 1 < m)
                    dp[l+1][i][j+1] = min(dp[l+1][i][j+1], dp[l][i][j] + hori[i][j]);
            }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++)
            cout << dp[k][i][j] * 2 << " ";
        cout << "\n";
    }

    return 0;
}