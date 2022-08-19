#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define maxn 300005
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
vi eg[maxn];
int n, x, y;
int fa[maxn], sz[maxn];
int fr[maxn];
void dfs(int a) {
    sz[a] = 1;
    for (auto v : eg[a]) {
        if (v == fa[a]) continue;
        if (fr[a] == 0) fr[v] = v;
        else fr[v] = fr[a];
        fa[v] = a;
        dfs(v);
        sz[a] += sz[v];
    }
}
int main() {
    cin >> n >> x >> y;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        eg[u].pb(v), eg[v].pb(u);
    }
    dfs(y);
    ll ans = 1ll * n * (n - 1);
    ll ban = 1ll * sz[x] * (n - sz[fr[x]]);
    ans -= ban;
    cout << ans << endl;
    return 0;
}
//can't first x the