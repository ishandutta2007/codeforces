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

bool vis[200005];
vector<int> curComp, adj[200005];

void dfs(int node) {
    for (int x : adj[node])
        if (!vis[x]) {
            vis[x] = true;
            curComp.push_back(x);
            dfs(x);
        }
}

int dfs2(int u, int p, int t) {
    if (u == t)
        return 1;
    vis[u] = true;
    for (int v : adj[u])
        if (v != p)
            return 1 + dfs2(v, u, t);
    return -1e9;
}

int cycle(const vector<int> &comp) {
    int amt = 0;
    for (int x : comp)
        amt += adj[x].size();
    return amt / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<vector<int>> comp;
    for (int i=1; i<=n; i++) {
        curComp.clear();
        if (!vis[i]) {
            vis[i] = true;
            curComp.push_back(i);
            dfs(i);
            comp.push_back(curComp);
        }
    }
    memset(vis, false, sizeof(vis));

    int tot = 0;
    for (vector<int> &cur : comp) {
        if (cycle(cur) == (int) cur.size() && dfs2(adj[cur[0]][0], cur[0], cur[0]) == (int) cur.size())
            tot++;
    }
    cout << tot << "\n";

    return 0;
}