//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 200005;
vector<pi> eg[maxn];
int u[maxn], v[maxn], w[maxn];
int f[maxn];
int fa[maxn], col[maxn];
int gfa(int a) {
    if (a == fa[a]) return a;
    int xf = gfa(fa[a]);
    col[a] ^= col[fa[a]];
    fa[a] = xf; return xf;
}
int flag;
void lk(int u, int v, int c) {
    int uf = gfa(u), vf = gfa(v);
    if (uf == vf) {
        if ((col[u] ^ col[v]) != c) 
            flag = 0; 
        return ;
    }
    fa[uf] = vf, col[uf] = col[u] ^ col[v] ^ c;
    return ;
}
int fw[maxn];
void dfs(int a) {
    for (auto v : eg[a]) {
        if (v.fi == f[a]) continue;
        f[v.fi] = a, fw[v.fi] = w[v.se], dfs(v.fi);
    }
}
void dfs2(int a) {
    for (auto v : eg[a]) {
        if (v.fi == f[a]) continue;
        if (w[v.se] == -1) {
            int g = v.fi;
            int gf = gfa(g), cf = gfa(a);
            int ncol = 0;
            if (gf == cf) ncol = col[g] ^ col[a];
            lk(g, a, ncol);
            w[v.se] = ncol;
        } 
        dfs2(v.fi);
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            f[i] = 0, fa[i] = i, col[i] = 0, eg[i].clear();
        for (int i = 1; i < n; i++) {
            scanf("%d%d%d", &u[i], &v[i], &w[i]);
            eg[u[i]].pb(mp(v[i], i));
            eg[v[i]].pb(mp(u[i], i));
        }
        flag = 1;
        for (int i = 1; i <= m; i++) {
            int x, y, d;
            scanf("%d%d%d", &x, &y, &d);
            lk(x, y, d);
        }
        dfs(1);
        for (int i = 1; i <= n; i++) 
            if (f[i] && fw[i] != -1) 
                lk(f[i], i, __builtin_popcount(fw[i]) % 2);
        dfs2(1);
        if (flag == 0) printf("NO\n");
        else {
            printf("YES\n");
            for (int i = 1; i < n; i++)
                printf("%d %d %d\n", u[i], v[i], w[i]);
        }
    }
    return (0-0); //<3
}