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
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

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

        int r = -1, w = -1;
        bool ok = true;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 'R') {
                    if (r == -1 || r == (i + j) % 2)
                        r = (i + j) % 2;
                    else
                        ok = false;
                } else if (grid[i][j] == 'W') {
                    if (w == -1 || w == (i + j) % 2)
                        w = (i + j) % 2;
                    else
                        ok = false;
                }
            }
        if (!ok || (r != -1 && r == w)) {
            cout << "NO\n";
            continue;
        }
        DEBUG(r, w);

        if (r == -1)
            r = w == 0 ? 1 : 0;
        if (w == -1)
            w = r == 0 ? 1 : 0;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                if (grid[i][j] == '.')
                    grid[i][j] = (i + j) % 2 == r ? 'R' : 'W';

        cout << "YES\n";
        for (const string &s : grid)
            cout << s << "\n";
    }

    return 0;
}