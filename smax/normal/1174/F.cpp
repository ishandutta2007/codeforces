#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

int depthX, depth[200000], sub[200000];
vector<int> path, adj[200000];

int query(char c, int u) {
    cout << c << " " << u + 1 << endl;
    int ret;
    cin >> ret;
    return ret;
}

int dfsSub(int u, int p) {
    sub[u] = 1;
    for (int v : adj[u])
        if (v != p) {
            depth[v] = depth[u] + 1;
            sub[u] += dfsSub(v, u);
        }
    return sub[u];
}

void dfsHld(int u, int p) {
    path.push_back(u);
    int nxt = -1;
    for (int v : adj[u])
        if (v != p && (nxt == -1 || sub[v] > sub[nxt]))
            nxt = v;
    if (nxt != -1)
        dfsHld(nxt, u);
}

int dfs(int u, int p) {
    path.clear();
    dfsHld(u, p);
    DEBUG(path)
    int depthY = (depthX + depth[path.back()] - query('d', path.back())) / 2, y = path[depthY - depth[u]];
    DEBUG(depthX, depthY)
    if (depthX == depthY)
        return y;
    return dfs(query('s', y) - 1, y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    depthX = query('d', 0);

    depth[0] = 0;
    dfsSub(0, -1);

    cout << "! " << dfs(0, -1) + 1 << endl;

    return 0;
}