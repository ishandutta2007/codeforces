#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 998244353
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 500005
int n, k;
vector<pll> e[MN];
ll dp[MN][2]; //base score, amt using improves

void dfs(int cn, int p){
    ll sm=0;
    vll imp;
    ll up=0;
    F0R(i, e[cn].size()){
        int nn = e[cn][i].f;
        ll sc = e[cn][i].s;
        if(nn == p){
            up = sc;
            continue;
        }
        
        dfs(nn, cn);
        sm += dp[nn][0];
        imp.pb(dp[nn][1]);
    }
    sort(imp.begin(), imp.end(), greater<ll>());
    F0R(i, min(k, (int)imp.size())){
        sm += imp[i];
        //cout << "adding " << imp[i] << "\n";
    }
    if(imp.size() < k){
        dp[cn][1] = up;
    } else{
        dp[cn][1] = max(0LL, up-imp[k-1]);
    }
    dp[cn][0] = sm;
    //cout << cn << " " << dp[cn][0] << " " << dp[cn][1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    F0R(_, q){
        cin >> n >> k;
        F0R(_, n-1){
            int u, v, w;
            cin >> u >> v >> w;
            e[u].pb({v, w});
            e[v].pb({u, w});
        }

        dfs(1, 0);
        cout << dp[1][0] << "\n";
        FOR(i, 1, n){
            e[i].clear();
            dp[i][0] = 0;
            dp[i][1] = 0;
        }
    }
    
    return 0;
}