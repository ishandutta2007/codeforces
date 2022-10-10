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

struct DSU {
    vector<int> par, sz;

    DSU(int n) : par(n), sz(n, 1) {
        iota(par.begin(), par.end(), 0);
    }

    int find(int u) {
        return u == par[u] ? u : par[u] = find(par[u]);
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        if (sz[u] < sz[v])
            swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return true;
    }
};

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (string &s : grid)
        cin >> s;

    DSU dsu(n * m);
    for (int r=0; r<n; r++)
        for (int c=0; c<m; c++)
            if (grid[r][c] == '.')
                for (int i=0; i<4; i++) {
                    int nr = r + dr[i], nc = c + dc[i];
                    if (0 <= nr && nr < n && 0 <= nc && nc < m && grid[nr][nc] == '.')
                        dsu.unite(r * m + c, nr * m + nc);
                }

    for (int r=0; r<n; r++)
        for (int c=0; c<m; c++)
            if (grid[r][c] == '*') {
                set<int> st;
                for (int i=0; i<4; i++) {
                    int nr = r + dr[i], nc = c + dc[i];
                    if (0 <= nr && nr < n && 0 <= nc && nc < m && grid[nr][nc] == '.')
                        st.insert(dsu.find(nr * m + nc));
                }
                int ret = 1;
                for (int u : st)
                    ret += dsu.sz[u];
                grid[r][c] = char('0' + ret % 10);
            }

    for (const string &s : grid)
        cout << s << "\n";

    return 0;
}