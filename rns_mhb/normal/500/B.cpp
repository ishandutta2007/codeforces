#include <bits/stdc++.h>
using namespace std;
#define N 333
#define inf 1000000007
#define eps 1e-7
#define pi acos(-1)
#define gc getchar
#define pc putchar
#define pb push_back

typedef pair <int, int> pii;
typedef long long ll;

template <class T>
inline void chkmax(T &x, T y) {if (x < y) x = y;}

template <class T>
inline void chkmin(T &x, T y) {if (x > y) x = y;}

int n, p[N], q[N];
vector <int> vec, nvec, adj[N];
bool vis[N];

void dfs(int u) {
    vis[u] = 1;
    vec.pb(p[u]), nvec.pb(u);
    int i, v, sz = adj[u].size();
    for (i = 0; i < sz; i ++) {
        v = adj[u][i];
        if (!vis[v]) dfs(v);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &p[i]);
    for (int i = 1; i <= n; i ++) {
        gc();
        for (int j = 1; j <= n; j ++)
            if (gc() == '1') adj[i].pb(j);
    }
    for (int i = 1; i <= n; i ++) {
        if (vis[i]) continue;
        vec.clear(), nvec.clear(), dfs(i);
        sort(vec.begin(), vec.end());
        sort(nvec.begin(), nvec.end());
        int j, sz = vec.size();
        for (j = 0; j < sz; j ++)
            q[nvec[j]] = vec[j];
    }
    for (int i = 1; i <= n; i ++) printf("%d ", q[i]);

    return 0;
}