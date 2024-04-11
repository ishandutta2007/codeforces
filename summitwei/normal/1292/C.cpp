#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 3005
int n;
vi e[MN];
int d[MN][MN];
int p[MN][MN];
int sz[MN][MN];
ll dp[MN][MN];

void dfs(int cn, int cp, int rt){
    sz[rt][cn] = 1;
    for(auto nn : e[cn]) if(nn != cp){
        d[rt][nn] = d[rt][cn]+1;
        p[rt][nn] = cn;
        dfs(nn, cn, rt);
        sz[rt][cn] += sz[rt][nn];
    }
}
ll calc(int u, int v){
    if(u == v) return 0;
    if(dp[u][v] != -1) return dp[u][v];
    ll res = 1LL*sz[u][v]*sz[v][u]+max(calc(u, p[u][v]), calc(p[v][u], v));
    return dp[u][v] = res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(_, n-1){
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }
    FOR(i, 1, n){
        dfs(i, 0, i);
    }
    memset(dp, -1, sizeof dp);
    ll ans = 0;
    FOR(i, 1, n){
        FOR(j, 1, n){
            ans = max(ans, calc(i, j));
        }
    }
    cout << ans << "\n";
    
    return 0;
}