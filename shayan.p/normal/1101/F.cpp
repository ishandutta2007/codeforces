// Mikaeel_noob_e_sag_e

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

const int maxn=410,mod=1e9+7;
const ll inf=1e18;

vector<pair<int,pii> >v[maxn];// right/ const /number of refules
int pos[maxn];
ll dp[maxn][maxn],a[maxn];

int main(){
    ios_base::sync_with_stdio(0);cin.tie();
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
	cin>>a[i];
    }
    while(m--){
	int a,b,c,d;cin>>a>>b>>c>>d;
	v[a].PB({b,{c,d}});
    }
    ll ans=0;
    for(int l=1;l<=n;l++){
	if(v[l].empty()) continue;
	for(int i=0;i<=n;i++){
	    dp[l][i]=0;
	    pos[i]=i;
	}
	for(int r=l;r<=n;r++){
	    dp[r][0]=a[r]-a[l];
	}
	for(int r=l+1;r<=n;r++){
	    for(int i=1;i<=n;i++){
		while(dp[pos[i]][i-1] < a[r]-a[pos[i]]) ++pos[i];
		dp[r][i]=min( dp[pos[i]][i-1] , a[r]-a[pos[i]-1] );
	    }
	}
	for(auto x:v[l]){
	    ans=max(ans,dp[x.F][x.S.S]*1ll*x.S.F);
	}
    }
    return cout<<ans<<endl,0;
}