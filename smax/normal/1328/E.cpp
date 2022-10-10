
// Problem : E. Tree Queries
// Contest : Codeforces Round #629 (Div. 3)
// URL : https://codeforces.com/contest/1328/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

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

#define MAXN 200000

struct RMQ {
    vector<int> a;
    vector<vector<int>> spt;

    void init(int n, int *_a) {
        a.resize(n);
        spt.assign(1, vector<int>(n));
        for (int i=0; i<n; i++) {
            a[i] = _a[i];
            spt[0][i] = i;
        }

        for (int j=1; 1<<j<=n; j++) {
            spt.emplace_back(n - (1 << j) + 1);
            for (int i=0; i+(1<<j)<=n; i++) {
                if (a[spt[j-1][i]] < a[spt[j-1][i+(1<<(j-1))]])
                    spt[j][i] = spt[j-1][i];
                else
                    spt[j][i] = spt[j-1][i+(1<<(j-1))];
            }
        }
    }

    int query(int i, int j) {
        int k = 31 - __builtin_clz(j - i + 1);
        if (a[spt[k][i]] < a[spt[k][j-(1<<k)+1]])
            return spt[k][i];
        else
            return spt[k][j-(1<<k)+1];
    }
};

int idx, ti[MAXN], node[2*MAXN], depth[2*MAXN];
vector<int> adj[MAXN];
RMQ rmq;

void dfs(int u, int p, int d) {
    ti[u] = idx;
    node[idx] = u;
    depth[idx++] = d;
    for (int v : adj[u])
        if (v != p) {
            dfs(v, u, d + 1);
            node[idx] = u;
            depth[idx++] = d;
        }
}

int lca(int u, int v) {
    if (ti[u] > ti[v])
        swap(u, v);
    return rmq.query(ti[u], ti[v]);
}

void preprocess() {
    idx = 0;
    dfs(0, -1, 0);
    rmq.init(idx, depth);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    
    preprocess();
    
    while (m--) {
        int k;
        cin >> k;
        
        vector<int> v(k);
        int maxDepth = 0, d = -1;
        for (int i=0; i<k; i++) {
            cin >> v[i];
            v[i]--;
            if (depth[ti[v[i]]] > maxDepth)
                maxDepth = depth[ti[v[i]]], d = v[i];
        }
        
        bool ok = true;
        for (int u : v)
            if (depth[ti[u]] - depth[lca(u, d)] > 1) {
                ok = false;
                break;
            }
        
        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}