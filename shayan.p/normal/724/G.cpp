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
typedef pair<int,ll> pil;

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

vector<pil> v[maxn];
int mark[maxn],cnt[2][maxn],n;
ll xr[maxn],tw[300],gd;
vector< pair<ll,int> > good;

void Add(ll num){
    for(auto x:good){
	if(bit(num,x.S))
	    num^=x.F;
    }
    if(num!=0){
	int bt=__builtin_ctzll(num & -num);
	for(auto &x:good)
	    if(bit(x.F,bt))
		x.F^=num;
	good.PB({num,bt});
	gd=0;
	for(auto x:good)
	    gd|=x.F;
    }
}

int dfs1(int u,int par=-1){
    int SZ=1;
    mark[u]=1;
    for(pil p:v[u]){
	if(mark[p.F]==0){
	    xr[p.F]=xr[u]^p.S;
	    SZ+=dfs1(p.F,u);
	}
	else if(p.F!=par){
	    Add(xr[p.F]^xr[u]^p.S);
	}
    }
    return SZ;
}

int dfs2(int u,int bt){
    mark[u]=bt+10;
    cnt[1][u]=0;
    cnt[0][u]=1;
    for(pil p:v[u]){
	if(mark[p.F]!=bt+10){
	    dfs2(p.F,bt);
	    cnt[0][u]+=cnt[bit(p.S,bt)][p.F];
	    cnt[1][u]+=cnt[bit(p.S,bt)^1][p.F];
   	}
    }
    return 1ll*cnt[0][u]*cnt[1][u]%mod;
}

int solve(int u){
    good.clear();
    int ans=gd=0;
    int N=dfs1(u);
    ll C2=((1ll*N*(N-1))/2)%mod;
    if(!good.empty())
	ans=1ll*C2*tw[sz(good)-1] %mod *(gd %mod) %mod;
    for(int i=0;i<=61;i++){
	if(!bit(gd,i))
	    ans=(1ll*ans+(tw[i+sz(good)] * dfs2(u,i)))%mod;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    tw[0]=1;
    for(int i=1;i<300;i++)
	tw[i]=(tw[i-1]*2)%mod;
    int m;cin>>n>>m;
    while(m--){
	int a,b;ll c;cin>>a>>b>>c;
	v[a].PB({b,c});
	v[b].PB({a,c});
    }
    int ans=0;
    for(int i=1;i<=n;i++){
	if(mark[i]==0)
	    ans=(ans+solve(i))%mod;
    }
    if(ans<0) ans+=mod;
    return cout<<ans<<endl,0;
}