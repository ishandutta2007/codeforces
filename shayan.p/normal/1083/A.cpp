// Phoenix

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

const int maxn=3e5+10,mod=1e9+7;
const ll inf=1e18;

ll dp[maxn],w[maxn],ans;
vector<pll> v[maxn];

void dfs(int u,int par=-1){
    ll mx1=-1,mx2=-1;
    for(pll p:v[u]){
	if(p.F!=par){
	    dfs(p.F,u);
	    dp[u]=max(dp[u],dp[p.F]-p.S+w[u]);
	    if(mx1<dp[p.F]-p.S) mx2=mx1,mx1=dp[p.F]-p.S;
	    else if(mx2<dp[p.F]-p.S) mx2=dp[p.F]-p.S;
	}
    }
    dp[u]=max(dp[u],w[u]);
    ans=max(ans,dp[u]);
    ans=max(ans,mx1+mx2+w[u]);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    int n;cin>>n;
    for(int i=1;i<=n;i++){
	cin>>w[i];
    }
    for(int i=0;i<n-1;i++){
	int a,b;ll c;cin>>a>>b>>c;
	v[a].PB({b,c});
	v[b].PB({a,c});
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}