// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=2e18;
const ll maxn=2e5+10;

#pragma GCC Optimize("Ofast")

vector<pll>v[maxn];
ll h[maxn];
bool mark[maxn];
ll w[maxn];
ll cut,cutind;
ll forb=-1;
ll n,m,s,t;

pair<ll,bool> dfs_cut(ll u,ll par=-1,ll ind=-1){
	bool chk=(u==t);
	mark[u]=1;
	ll ret=h[u];
	REP(i,sz(v[u])){
		ll y=v[u][i].F;
		ll idx=v[u][i].S;
		
		if(idx==forb)// no forb
			continue;
			
		if(!mark[y]){
			h[y]=h[u]+1;
			pair<ll,bool> p=dfs_cut(y,u,idx);
			ret=min(ret,p.F);
			chk|=p.S;
		}
		else if(idx!=ind){
			ret=min(ret,h[y]);
		}
	}
	if(chk){
		if(ret==h[u]&&u!=s){
			if(w[ind]<cut){
				cut=w[ind];
				cutind=ind;
			}
		}
	}
	return MP(ret,chk);
}

void connect(ll u,ll ind=-1){
	mark[u]=1;
	REP(i,sz(v[u])){
		ll y=v[u][i].F;
		ll ed=v[u][i].S;
		
		if(ed==forb)
			continue;
			
		if(!mark[y])
			connect(y,ed);
	}
}

pll bef[maxn];// befor // edge number

void dfs(ll u){
	REP(i,sz(v[u])){
		ll y=v[u][i].F;
		ll ind=v[u][i].S;
		if(bef[y].F==0){
			bef[y]=MP(u,ind);
			dfs(y);
		}
	}
}

int main(){
	cin>>n>>m;
	cin>>s>>t;
	REP(i,m){
		ll a,b;cin>>a>>b>>w[i];
		v[a].PB(MP(b,i));
		v[b].PB(MP(a,i));
	}
	bef[s].F=-1;
	dfs(s);
	if(bef[t].F==0){
		cout<<0<<endl<<0;
		return 0;
	}
	ll tmp=t;
	vector<ll>edg;
	while(tmp!=-1){
		edg.PB(bef[tmp].S);
		tmp=bef[tmp].F;
	}
	
	ll ans=inf;
	pll ansind=MP(-1,-1);
	REP(i,sz(edg)){
		forb=edg[i];
		cut=inf;
		memset(mark,0,sizeof mark);
		connect(s);
		if(!mark[t]){
			if(ans>w[edg[i]]){
				ans=w[edg[i]];
				ansind=MP(edg[i],-1);
			}
			continue;
		}
		memset(mark,0,sizeof mark);
		dfs_cut(s);
		if(ans>w[edg[i]]+cut){
			ans=w[edg[i]]+cut;
			ansind=MP(edg[i],cutind);
		}
	}
	ll num=(ansind.F!=-1)+(ansind.S!=-1);
	if(ans==inf)
		cout<<-1;
	else{
		cout<<ans<<endl<<num<<endl;
		if(num==1)cout<<ansind.F+1;
		else cout<<ansind.F+1<<" "<<ansind.S+1;
	}
}