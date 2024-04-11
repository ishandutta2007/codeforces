#include <bits/stdc++.h>
using namespace std;
#define N 200010
#define inf 1000000000
#define ep 1e-9
#define mp make_pair
#define pb push_back
template<class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template<class T> void chkmin(T &a, T b) {if (a > b) a = b;}
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, a[N], mx[N];
vector<int> d[N];
vector<int> adj[N];

void dfs(int u, int pa, bool id, int mod) {
    bool id1 = id;
    if (a[u] % mod) {
        if (!id) id1 = 1;
        else return;
    }
    chkmax(mx[u], mod);
    for (int i = 0, v; i < adj[u].size(); i ++) {
        v = adj[u][i];
        if (v != pa) dfs(v, u, id1, mod);
    }
}

int main() {
    for (int i = 1; i < N; i ++) {
        for (int j = i; j < N; j += i) d[j].pb(i);
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", a + i);
    int m = n - 1, u, v;
    while (m --) {
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i = 1; i <= n; i ++) mx[i] = 1;
    int sup = *max_element(a + 1, a + n + 1);
    for (int i = 0; i < d[a[1]].size(); i ++) dfs(1, -1, 0, d[a[1]][i]);
    for (int i = 0, u; i < adj[1].size(); i ++) {
        u = adj[1][i];
        for (int j = 0; j < d[a[u]].size(); j ++) {
            if (a[1] % d[a[u]][j]) dfs(u, 1, 1, d[a[u]][j]);
        }
    }
    mx[1] = a[1];
    for (int i = 1; i <= n; i ++) printf("%d ", mx[i]);
}