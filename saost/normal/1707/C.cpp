#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
#define getbit(x, i) (((x) >> (i)) & 1)
using namespace std;
const int N = 100005;
int t, n, m, high[N], dad[N], p[N][20], pre[N];
vector<int> S[N];
vector<pair<int, int>> Q;

int DAD(int u) {
    return (dad[u] < 0 ? u : dad[u] = DAD(dad[u]));
}

bool Union(int u, int v) {
    u = DAD(u);
    v = DAD(v);
    if (u == v) return false;
    if (dad[u] > dad[v]) swap(u, v);
    dad[u] += dad[v];
    dad[v] = u;
    return true;
}

void Enter() {
    cin >> n >> m;
    fill(dad + 1, dad + n + 1, -1);
    FOR(i, 1, m) {
        int u, v;
        cin >> u >> v;
        if (Union(u, v)) {
            S[u].push_back(v);
            S[v].push_back(u);
        }
        else Q.emplace_back(u, v);
    }
}

void DFS(int u, int pa) {
    high[u] = high[pa] + 1;
    p[u][0] = pa;
    REP(i, 1, 20) p[u][i] = p[p[u][i - 1]][i - 1];

    for(int v : S[u]) if (v != pa)
        DFS(v, u);
}

int LCA(int u, int v) {
    if (high[u] > high[v]) swap(u, v);
    int diff = high[v] - high[u];
    REPD(i, 20, 0) if (getbit(diff, i)) v = p[v][i];
    if (u == v) return u;
    REPD(i, 20, 0) if (p[u][i] != p[v][i]) u = p[u][i], v = p[v][i];
    return p[u][0];
}


int pre_LCA(int u, int v) {
    if (high[u] > high[v]) swap(u, v);
    int diff = high[v] - high[u] - 1;
    REPD(i, 20, 0) if (getbit(diff, i)) v = p[v][i];
    return v;
}

void DFS2(int u, int p) {
    pre[u] += pre[p];
    for(int v : S[u]) if (v != p)
        DFS2(v, u);
}

void Process() {
    DFS(1, 0);
    for(auto [u, v] : Q) {
        if (high[u] > high[v]) swap(u, v);
        int pa = LCA(u, v);
        if (pa != u) {
            ++pre[u];
            ++pre[v];
        }
        else {
            ++pre[1];
            ++pre[v];
            --pre[pre_LCA(u, v)];
        }
    }
    DFS2(1, 0);
    FOR(i, 1, n) cout << (pre[i] == Q.size());
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    t = 1;
    while (t--) {
        Enter();
        Process();
    }
}