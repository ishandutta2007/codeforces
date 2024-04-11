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
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=510;
const ll maxe=1e5+10;

vector<pll>v[maxn];
int mark[maxn];
vector<ll>cycle;
int forb=-1;

bool cycle_find(ll u,ll bef=0){
	if(mark[u]==-1){
		cycle.PB(bef);
		return 1;
	}
	if(mark[u]==1){
		return 0;
	}
	mark[u]=-1;
	REP(i,sz(v[u])){
		ll y=v[u][i].F;
		ll id=v[u][i].S;
		if(cycle_find(y,id)){
			cycle.PB(bef);
			return 1;
		}
	}
	mark[u]=1;
	return 0;
}
bool cycle_check(ll u){
	if(mark[u]==-1){
		mark[u]=1;
		return 1;
	}
	if(mark[u]==1)
		return 0;
	mark[u]=-1;
	REP(i,sz(v[u])){
		ll y=v[u][i].F;
		ll id=v[u][i].S;
		if(forb==id)
			continue;
		if(cycle_check(y)){
			mark[u]=1;
			return 1;
		}
	}
	mark[u]=1;
	return 0;
}

int main(){
	ll n,m;cin>>n>>m;
	REP(i,m){
		ll a,b;cin>>a>>b;
		a--;b--;
		v[a].PB(MP(b,i));
	}
	bool yes=0;
	REP(i,n){
		if(mark[i]==0){
			yes=cycle_find(i);
			if(yes)
				break;
		}
	}
	if(!yes){
		cout<<"YES";
		return 0;
	}
	yes=0;
	REP(i,sz(cycle)){
		forb=cycle[i];
		memset(mark,0,sizeof mark);
		bool any=0;
		REP(j,n){
			any|=cycle_check(j);
		}
		yes|=(!any);
	}
	if(yes)
		cout<<"YES";
	else
		cout<<"NO";
}