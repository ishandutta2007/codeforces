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

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

struct SCC {
    int n, ti;
    vector<int> num, id, stk;
    vector<vector<int>> adj, dag, comp;

    SCC(int _n) : n(_n), ti(0), num(n), id(n, -1), adj(n) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void init() {
        for (int u=0; u<n; u++)
            if (!num[u])
                dfs(u);
        dag.resize(comp.size());
        for (auto &c : comp)
            for (int u : c)
                for (int v : adj[u])
                    if (id[u] != id[v])
                        dag[id[u]].push_back(id[v]);
        for (auto &v : dag) {
            sort(v.begin(), v.end());
            v.erase(unique(v.begin(), v.end()), v.end());
        }
    }

    int dfs(int u) {
        int low = num[u] = ++ti;
        stk.push_back(u);
        for (int v : adj[u]) {
            if (!num[v])
                low = min(low, dfs(v));
            else if (id[v] == -1)
                low = min(low, num[v]);
        }
        if (low == num[u]) {
            comp.emplace_back();
            do {
                id[stk.back()] = (int) comp.size() - 1;
                comp.back().push_back(stk.back());
                stk.pop_back();
            } while (comp.back().back() != u);
        }
        return low;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i=0; i<n; i++)
        cin >> grid[i];
    vector<int> a(m);
    for (int i=0; i<m; i++)
        cin >> a[i];

    auto encode = [&] (int r, int c) -> int {
        return r * m + c;
    };

    vector<vector<int>> stk(m);
    for (int i=n-1; i>=0; i--)
        for (int j=0; j<m; j++)
            if (grid[i][j] == '#')
                stk[j].push_back(i);

    SCC scc(n * m);
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (grid[i][j] == '#') {
                assert(stk[j].back() == i);
                stk[j].pop_back();
                int u = encode(i, j);
                if (j > 0 && !stk[j-1].empty())
                    scc.addEdge(u, encode(stk[j-1].back(), j - 1));
                if (!stk[j].empty())
                    scc.addEdge(u, encode(stk[j].back(), j));
                if (j + 1 < m && !stk[j+1].empty())
                    scc.addEdge(u, encode(stk[j+1].back(), j + 1));
                for (int d=0; d<4; d++) {
                    int nr = i + dr[d], nc = j + dc[d];
                    if (0 <= nr && nr < n && 0 <= nc && nc < m && grid[nr][nc] == '#')
                        scc.addEdge(u, encode(nr, nc));
                }
            }

    scc.init();
    vector<int> deg(n * m), top;
    for (int u=(int)scc.comp.size()-1; u>=0; u--) {
        if (grid[scc.comp[u][0] / m][scc.comp[u][0] % m] == '.')
            continue;
        if (deg[u] == 0)
            top.push_back(u);
        for (int v : scc.dag[u])
            deg[v]++;
    }

    sort(top.begin(), top.end(), [&] (int u, int v) -> bool {
        return scc.comp[u][0] % m < scc.comp[v][0] % m;
    });
    vector<int> l(n * m, -1), r(n * m, -1);

    auto dfs1 = [&] (auto &self, int u, int i) -> void {
        l[u] = i;
        for (int v : scc.dag[u])
            if (l[v] == -1)
                self(self, v, i);
    };

    auto dfs2 = [&] (auto &self, int u, int i) -> void {
        r[u] = i;
        for (int v : scc.dag[u])
            if (r[v] == -1)
                self(self, v, i);
    };

    for (int i=0; i<(int)top.size(); i++)
        dfs1(dfs1, top[i], i);
    for (int i=(int)top.size()-1; i>=0; i--)
        dfs2(dfs2, top[i], i);

    vector<int> intervals;
    for (int i=n-1; i>=0; i--)
        for (int j=0; j<m; j++)
            if (grid[i][j] == '#' && --a[j] == 0)
                intervals.push_back(scc.id[encode(i, j)]);

    sort(intervals.begin(), intervals.end(), [&] (int i, int j) -> bool {
        return r[i] < r[j];
    });
    int ret = 0, last = -1;
    for (int i : intervals)
        if (l[i] > last) {
            ret++;
            last = r[i];
        }
    cout << ret << "\n";

    return 0;
}