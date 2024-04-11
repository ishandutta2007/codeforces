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
int n;
vi eg[maxn];
int fl[maxn], fa[maxn];
int d[maxn];
vector<pi> tot;
mt19937 rd;
void dfs(int a) {
    for (auto v : eg[a]) {
        if (v == fa[a]) continue;
        fa[v] = a;
        dfs(v);
    }
    while (1) {
        int cnt = 0;
       // shuffle(eg[a].begin(), eg[a].end(), rd);
        for (auto v : eg[a]) {
            if (v == fa[a] || (!fl[v])) continue;
            if ((d[v] & 1) == (d[a] & 1)) {
                fl[v] = 0;
                tot.pb(mp(v, a));
                d[a] ^= 1, d[v] ^= 1;
                cnt = 1;
            }
        }
        if (!cnt) break;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) eg[i].clear(), d[i] = 0;
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            eg[u].pb(v);
            eg[v].pb(u);
            d[u] ^= 1, d[v] ^= 1;
        }
        for (int i = 1; i <= n; i++) fl[i] = 1;
        tot.clear();
        while (1) {
            int f = tot.size();
            dfs(1);
            int e = tot.size();
            if (f == e) 
break;
        }
        if (tot.size() == n - 1) {
            printf("YES\n");
            for (auto v : tot)
                printf("%d %d\n", v.fi, v.se);
        }
        else printf("NO\n");
    }
    return (0-0); //<3
}