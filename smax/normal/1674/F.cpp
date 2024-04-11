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

    int n, m, q;
    cin >> n >> m >> q;
    vector<string> grid(n);
    for (string &s : grid)
        cin >> s;

    vector bit(n + 1, vector<int>(m + 1));

    auto query = [&] (int x, int y) -> int {
        int ret = 0;
        for (int i=x+1; i>0; i-=i&-i)
            for (int j=y+1; j>0; j-=j&-j)
                ret += bit[i][j];
        return ret;
    };

    auto update = [&] (int x, int y, int v) -> void {
        for (int i=x+1; i<=n; i+=i&-i)
            for (int j=y+1; j<=m; j+=j&-j)
                bit[i][j] += v;
    };

    int cnt = 0;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            if (grid[i][j] == '.')
                update(i, j, 1);
            else
                cnt++;
        }

    for (int i=0; i<q; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (grid[x][y] == '.') {
            update(x, y, -1);
            cnt++;
            grid[x][y] = '*';
        } else {
            update(x, y, 1);
            cnt--;
            grid[x][y] = '.';
        }
        int cols = cnt / n, rem = cnt % n;
        cout << query(n - 1, cols - 1) + query(rem - 1, cols) - query(rem - 1, cols - 1) << "\n";
    }

    return 0;
}