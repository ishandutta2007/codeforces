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
int fa[maxn];
int mx[maxn]; // max erase
int dc[maxn], dle[maxn], dtp[maxn]; // kuaishu 
vi eg[maxn];
int tot[maxn];
void dfs(int a) {
    int cs = 0;
    dc[a] = 0, dle[a] = 0, dtp[a] = 1; // is leave
    tot[a] = 0;
    for (auto v : eg[a]) {
        if (v == fa[a]) continue;
        fa[v] = a; dfs(v);
        tot[a] += tot[v];
        dc[a] += dc[v];
        dle[a] += dle[v];
        if (dtp[v]) dtp[a] = 0;
    }
    if (eg[a].size() == 1 && a != 1) tot[a] = 1; // total leaves
    dle[a] += dtp[a];
    if (!dtp[a]) dc[a] += 1;
    mx[a] = 0;
    // one : mx other
    vector<pi> s;
    for (auto v : eg[a]) {
        if (v == fa[a]) continue;
        s.pb(mp(mx[v], tot[v] - (dle[v] - dc[v])));
    }
    if (!s.size()) mx[a] = 0;
    else {
        int inc = -1e9;
        for (auto v : s) mx[a] += v.se, chkmax(inc, v.fi -v.se);
        mx[a] += inc;
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) eg[i].clear();
        for (int j = 1; j < n; j++) {
            int u, v;
            scanf("%d%d", &u, &v);
            eg[u].pb(v), eg[v].pb(u);
        }
        dfs(1);
        int ans = tot[1] - mx[1];
        printf("%d\n", ans);
    }
    return (0-0); //<3
}