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

const ll inf=4e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

ll ans[maxn],pl[maxn];
ll mx=-1;
vector<ll>v[maxn];

void dfs(ll u,ll par=-1,ll bef=0){
	ans[u]=(bef%mx);
	bool seen=0,is=0;
	REP(i,sz(v[u])){
		ll y=v[u][i];
		seen|=(y==par);
		if(y!=par){
			if(par!=-1&&(((bef+i+1-seen)%mx)==ans[par]))
				is=1;
			dfs(y,u,bef+i+1-seen+is);
		}
	}
}

int main(){
	ll n;cin>>n;
	REP(i,n-1){
		ll a,b;cin>>a>>b;
		a--;b--;
		v[a].PB(b);
		v[b].PB(a);
	}
	REP(i,n)
		mx=max(mx,ll(sz(v[i])+1));
		
	dfs(0);
	cout<<mx<<endl;
	REP(i,n)
		cout<<ans[i]+1<<" ";
}