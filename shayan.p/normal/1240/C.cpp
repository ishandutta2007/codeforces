// Remember...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=5e5+10,mod=1e9+7;
const ll inf=1e18;

ll dp[2][maxn];
vector<pii> v[maxn];
int n,k;

void dfs(int u,int par=0){
    
    for(pii p:v[u]){
	if(p.F!=par)
	    dfs(p.F,u), dp[1][u]+= dp[0][p.F];
    }
    sort(v[u].begin(), v[u].end(), [](pii a,pii b){ return dp[1][a.F]-dp[0][a.F]+a.S > dp[1][b.F]-dp[0][b.F]+b.S; } );
    int cnt=0;
    dp[0][u]=dp[1][u];
    for(pii p:v[u]){
	if(dp[1][p.F] - dp[0][p.F] + p.S <= 0) break;
	if(p.F!=par){
	    cnt++;
	    if(cnt==k){
		dp[0][u]+= dp[1][p.F] - dp[0][p.F] + p.S;
		break;
	    }
	    else{
		dp[1][u]+= dp[1][p.F] - dp[0][p.F] + p.S;
		dp[0][u]= dp[1][u];
	    }
	}
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q; cin>>q;

    while(q--){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
	    v[i].clear();
	    dp[0][i]= dp[1][i]= 0;
	}
	for(int i=0;i<n-1;i++){
	    int a,b,c; cin>>a>>b>>c;
	    v[a].PB({b,c});
	    v[b].PB({a,c});
	}
	dfs(1);
	cout<<dp[0][1]<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")