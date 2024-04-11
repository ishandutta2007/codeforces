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

#define MAXN 100000
#define MOD 1000000007

int modpow(int a, int b) {
    int ret = 1;
    while (b > 0) {
        if (b & 1)
            ret = (long long) ret * a % MOD;
        a = (long long) a * a % MOD;
        b >>= 1;
    }
    return ret;
}

int id, cycleId[MAXN];
bool visited[MAXN] = {}, backUp[MAXN] = {}, backDown[MAXN] = {};
vector<int> adj[MAXN];

void dfs(int u, int p = -1) {
    visited[u] = true;
    for (int v : adj[u])
        if (v != p) {
            if (!visited[v])
                dfs(v, u);
            else if (!backUp[v])
                backUp[u] = backDown[v] = true;
        }
    if (backUp[u])
        cycleId[u] = id++;
    else {
        cycleId[u] = u;
        for (int v : adj[u])
            if (v != p && cycleId[v] != v && !backDown[v])
                cycleId[u] = cycleId[v];
    }
}

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

int n, idx, ti[2*MAXN], node[4*MAXN], depth[4*MAXN], dp[2*MAXN];
vector<int> nadj[2*MAXN];
RMQ rmq;

void dfs(int u, int p, int d) {
    ti[u] = idx;
    node[idx] = u;
    depth[idx++] = d;
    dp[u] = (u >= n) + (p != -1 ? dp[p] : 0);
    for (int v : nadj[u])
        if (v != p) {
            dfs(v, u, d + 1);
            node[idx] = u;
            depth[idx++] = d;
        }
}

int lca(int u, int v) {
    if (ti[u] > ti[v])
        swap(u, v);
    return node[rmq.query(ti[u], ti[v])];
}

void preprocess() {
    idx = 0;
    dfs(cycleId[0], -1, 0);
    rmq.init(idx, depth);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    id = n;
    dfs(0);
    for (int u=0; u<n; u++)
        for (int v : adj[u])
            if (cycleId[u] != cycleId[v]) {
                nadj[cycleId[u]].push_back(cycleId[v]);
                nadj[cycleId[v]].push_back(cycleId[u]);
            }
    for (int i=0; i<2*n; i++) {
        sort(nadj[i].begin(), nadj[i].end());
        nadj[i].erase(unique(nadj[i].begin(), nadj[i].end()), nadj[i].end());
    }
    preprocess();

    int k;
    cin >> k;
    for (int i=0; i<k; i++) {
        int x, y;
        cin >> x >> y;
        x = cycleId[x-1], y = cycleId[y-1];
        int z = lca(x, y), cnt = dp[x] + dp[y] - 2 * dp[z] + (z >= n);
        cout << modpow(2, cnt) << "\n";
    }

    return 0;
}