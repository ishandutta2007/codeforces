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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for (int i=0; i<n; i++)
            cin >> grid[i];

        vector<vector<int>> pref(n, vector<int>(m));
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                pref[i][j] = (grid[i][j] == '*') + (j > 0 ? pref[i][j-1] : 0);

        int ret = 0;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                if (grid[i][j] == '*') {
                    int len = 1;
                    while (len + 1 <= n - i && len <= j && len <= m - j - 1 && pref[i + len][j + len] - (j - len > 0 ? pref[i + len][j - len - 1] : 0) == 2 * len + 1)
                        len++;
                    ret += len;
                }
        cout << ret << "\n";
    }

    return 0;
}