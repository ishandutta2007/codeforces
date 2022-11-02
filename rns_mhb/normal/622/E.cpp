#include <bits/stdc++.h>
using namespace std;
#define N 500100
#define inf 1000000000
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

int n, ans, maxi, d[N];
vector <int> vec, adj[N];

void dfs(int u, int pa) {
    int i, v, sz = adj[u].size();
    d[u] = d[pa] + 1;
    if (sz == 1) vec.pb(d[u]);
    for (i = 0; i < sz; i ++) {
        v = adj[u][i];
        if (v == pa) continue;
        dfs(v, u);
    }
}

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    int x, y, i, j, sz, len;
    scanf("%d", &n);
    for (i = 1; i < n; i ++)
        scanf("%d %d", &x, &y), adj[x].pb(y), adj[y].pb(x);
    sz = adj[1].size();
    for (i = 0; i < sz; i ++) {
        vec.clear(), dfs(adj[1][i], 1);
        len = vec.size(); maxi = 0;
        sort(vec.begin(), vec.end());
        for (j = 0; j < len; j ++) maxi = max(maxi + 1, vec[j]);
        chkmax(ans, maxi);
    }
    printf("%d\n", ans);

    return 0;
}