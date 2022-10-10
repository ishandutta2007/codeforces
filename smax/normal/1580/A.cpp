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

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<bool>> a(n, vector<bool>(m));
        for (int i=0; i<n; i++) {
            string s;
            cin >> s;
            for (int j=0; j<m; j++)
                a[i][j] = s[j] == '1';
        }

        vector<vector<int>> pref(m, vector<int>(n));
        for (int j=0; j<m; j++)
            for (int i=0; i<n; i++)
                pref[j][i] = a[i][j] + (i > 0 ? pref[j][i-1] : 0);

        int ret = INF;
        for (int i=0; i+4<n; i++)
            for (int j=i+4; j<n; j++) {
                int mn = INF, window = 0;
                for (int k=0; k<m; k++) {
                    if (k >= 3) {
                        window -= !a[i][k-3] + !a[j][k-3] + pref[k-3][j-1] - pref[k-3][i];
                        mn = min(mn, window + j - i - 1 - (pref[k-3][j-1] - pref[k-3][i]));
                        ret = min(ret, mn + j - i - 1 - (pref[k][j-1] - pref[k][i]));
                    }
                    mn += !a[i][k] + !a[j][k] + pref[k][j-1] - pref[k][i];
                    window += !a[i][k] + !a[j][k] + pref[k][j-1] - pref[k][i];
                }
            }
        cout << ret << "\n";
    }

    return 0;
}