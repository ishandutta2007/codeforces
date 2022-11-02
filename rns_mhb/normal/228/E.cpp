//7
#include <bits/stdc++.h>
using namespace std;
#define N 111
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

int n, m;
bool d[N];
bool vis[N];
vector <pii> adj[N];
vector <int> vec;

bool dfs(int u) {
    vis[u] = 1;
    if (d[u] == 1) vec.pb(u);
    int i, v, ad, sz = adj[u].size();
    for (i = 0; i < sz; i ++) {
        v = adj[u][i].first;
        ad = adj[u][i].second;
        if (vis[v]) {
            if (d[v] ^ d[u] ^ ad ^ 1) return 0;
            else continue;
        }
        else {
            d[v] = d[u] ^ ad ^ 1;
            if (!dfs(v)) return 0;
        }
    }
}

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d %d", &n, &m);
    while (m --) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        adj[a].pb(pii(b, c));
        adj[b].pb(pii(a, c));
    }
    bool fg = 1;
    for (int i = 1; i <= n; i ++) {
        if (!vis[i]) {
            d[i] = 1;
            if (!dfs(i)) fg = 0;
        }
    }
    if (fg) {
        int sz = vec.size();
        printf("%d\n", sz);
        for (int i = 0; i < sz; i ++) printf("%d ", vec[i]);
        puts("");
    }
    else puts("Impossible");

    return 0;
}