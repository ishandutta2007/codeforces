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

const ll mod=1e9+7;
const ll maxn=1e6+10;

long long self,other;
vector<ll>v[maxn];
bool mark[maxn];
bool is_loop[maxn];
void dfs(ll u){
	mark[u]=1;
	REP(i,sz(v[u])){
		ll y=v[u][i];
		if(!mark[y])
			dfs(y);
	}
}

int main(){
	ll n,m;scanf("%d%d",&n,&m);
	REP(i,m){
		ll a,b;
		scanf("%d%d",&a,&b);
		if(a==b){
			self++;
			is_loop[a]=1;
		}
		else{
			v[a].PB(b);
			v[b].PB(a);
			other++;
		}
	}
	
	FOR(i,1,n){
		if(sz(v[i])!=0||is_loop[i]){
			dfs(i);
			break;
		}
	}
	
	FOR(i,1,n){
		if(!mark[i]&&(sz(v[i])!=0||is_loop[i])){
			cout<<0;
			return 0;
		}
	}
	
	long long ans=0;
	FOR(i,1,n){
		long long l=sz(v[i]);
		ans+=((l)*(l-1))/2;
	}
	ans+=(self*other);
	ans+=(self*(self-1))/2;
	cout<<ans;
}