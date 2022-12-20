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
const ll maxn=1e5+10;

vector<ll>v[maxn],g[maxn];
ll val[maxn];
bool mark[maxn];
ll ans;
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
void modify(ll u,ll num){
	ans=gcd(ans,abs(val[u]-num));
}
void dfs(ll u,ll num=0){
	if(mark[u]==1){
		modify(u,num);
		return;
	}
	mark[u]=1;
	val[u]=num;
	REP(i,sz(v[u]))
		dfs(v[u][i],num+1);
	REP(i,sz(g[u]))
		dfs(g[u][i],num-1);
}
int main(){
	ll n,m;cin>>n>>m;
	set<pll>s;
	ll cnt=1;
	FOR(i,1,m){
		ll a,b;cin>>a>>b;
		if(!s.count(MP(a,b))){
			s.insert(MP(a,b));
			v[a].PB(b);
			g[b].PB(a);
		}
	}
	FOR(i,1,n){
		if(!mark[i]){
			dfs(i);
		}
	}
	if(ans==0)cout<<n;
	else cout<<ans;
}