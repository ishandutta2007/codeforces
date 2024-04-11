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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=1e18;
const ll maxn=3e5+10;

vector<ll>v[maxn];
ll Sz[maxn],ans[maxn],h;
deque<ll> deq[maxn];

void dfs(ll u,deque<ll>&d){
	d.PB(u);
	if(sz(v[u])==0){
		while(sz(d)){
			ans[d[0]]=u;
			d.POF();
		}
		return;
	}
	ll ind=-1,mx=v[u][0];
	REP(i,sz(v[u])){
		ll y=v[u][i];
		if(Sz[y]>Sz[mx])
			mx=y;
	}
	while(sz(d)&&((Sz[d[0]]-1)/2)>=Sz[mx]){
		ans[d[0]]=u;
		d.POF();
	}
	dfs(mx,d);
	REP(i,sz(v[u])){
		ll y=v[u][i];
		if(y!=mx)
			dfs(y,deq[++h]);
	}
}
void Size(ll u){
	Sz[u]=1;
	REP(i,sz(v[u])){
		ll y=v[u][i];
		Size(y);
		Sz[u]+=Sz[y];
	}
}
int main(){
	ll n,q;cin>>n>>q;
	FOR(i,2,n){
		ll x;cin>>x;
		v[x].PB(i);
	}
	Size(1);
	dfs(1,deq[0]);
	REP(i,q){
		ll a;cin>>a;
		cout<<ans[a]<<endl;
	}
}