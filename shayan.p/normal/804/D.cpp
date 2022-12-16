// Jump, and you will find out how to unfold your wings as you fall.

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
typedef long double ld;

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

vector<int>v[maxn],ds[maxn];
vector<ll>smd[maxn];
int mark[maxn],mds[maxn],sp[20][maxn],h[maxn],C;
map<pii,ld> mp;

pii far(int u,int par=0){
    pii ans={0,u};
    for(int y:v[u]){
	if(y!=par){
	    pii num=far(y,u);
	    num.F++;
	    ans=max(ans,num);
	}
    }
    return ans;
}
void fil(int u,int par=0){
    sp[0][u]=par;
    for(int i=1;i<20;i++)
	sp[i][u]=sp[i-1][sp[i-1][u]];
    h[u]=h[par]+1;
    ds[C].PB(u);
    mark[u]=C;
    for(int y:v[u]){
	if(y!=par)
	    fil(y,u);
    }
}

int Lca(int a,int b){
    if(h[a]<h[b]) swap(a,b);
    for(int i=19;i>=0;i--){
	if(h[sp[i][a]]>=h[b])
	    a=sp[i][a];
    }
    if(a==b) return a;
    for(int i=19;i>=0;i--){
	if(sp[i][a]!=sp[i][b])
	    a=sp[i][a],b=sp[i][b];
    }
    return sp[0][a];
}

int Dis(int a,int b){
    return h[a]+h[b]-2*h[Lca(a,b)];
}

void prep(int u){
    u=far(u).S;
    int y=far(u).S;
    fil(u);
    for(int i=0;i<sz(ds[C]);i++){
	ds[C][i]=max(Dis(ds[C][i],u),Dis(ds[C][i],y));
	mds[C]=max(mds[C],ds[C][i]);
    }
    sort(ds[C].begin(),ds[C].end());
    smd[C].resize(sz(ds[C])+1);
    for(int i=sz(ds[C])-1;i>=0;i--)
	smd[C][i]=smd[C][i+1]+ds[C][i];
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,q;cin>>n>>m>>q;
    for(int i=1;i<=m;i++){
	int a,b;cin>>a>>b;
	v[a].PB(b);
	v[b].PB(a);
    }
    for(int i=1;i<=n;i++){
	if(mark[i]==0){
	    ++C,prep(i);
	}
    }
    while(q--){
	int a,b;cin>>a>>b;
	a=mark[a],b=mark[b];
	if(sz(ds[a])>sz(ds[b])){
	    swap(a,b);
	}
	if(a==b){
	    cout<<"-1\n";
	}
	else if(mp.count({a,b})){
	    cout<<setprecision(10)<<fixed<<mp[{a,b}]<<"\n";
	}
	else{
	    ld ans=0;
	    int mx=max(mds[a],mds[b]);
	    for(int x:ds[a]){
		int id=lower_bound(ds[b].begin(),ds[b].end(),mx-1-x)-ds[b].begin();
		ans+=1ll*(x+1)*(sz(ds[b])-id) + smd[b][id] + 1ll*id*mx;
	    }
	    ans/=ld(sz(ds[a]))*ld(sz(ds[b]));
	    cout<<setprecision(10)<<fixed<<ans<<"\n";
	    mp[{a,b}]=mp[{b,a}]=ans;
	}
    }
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.