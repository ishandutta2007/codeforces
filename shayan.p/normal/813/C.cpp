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
const ll maxn=2e5+10;

bool mark[maxn];

ll depth[maxn];
ll way[maxn];
ll Par[maxn];
vector<ll>v[maxn];

void dfs(ll u,ll d,ll par=-1){
	depth[u]=d;
	way[u]=d;
	Par[u]=par;
	REP(i,sz(v[u])){
		ll y=v[u][i];
		if(y!=par){
			dfs(y,d+1,u);
			way[u]=max(way[u],way[y]);
		}
	}
}
int main(){
	ll n,x;cin>>n>>x;
	REP(i,n-1){
		ll a,b;cin>>a>>b;
		v[a].PB(b);
		v[b].PB(a);
	}
	dfs(1,0);
	ll tmp=x,ans=0,d=depth[x];
	while(tmp!=-1&&depth[tmp]>(d/2)){
		ans=max(ans,way[tmp]);
		tmp=Par[tmp];
	}
	cout<<2*ans;
}