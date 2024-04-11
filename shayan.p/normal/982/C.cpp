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
const ll maxn=1e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

vector<ll>v[maxn];
ll SZ[maxn],ans;

void dfs(ll u,ll par=-1){
	SZ[u]=1;
	REP(i,sz(v[u])){
		ll y=v[u][i];
		if(par!=y){
			dfs(y,u);
			SZ[u]+=SZ[y];
		}
	}
	ans+=(par!=-1&&SZ[u]%2==0);
}

int main(){
	ll n;cin>>n;
	REP(i,(n-1)){
		ll a,b;cin>>a>>b;
		v[a].PB(b);
		v[b].PB(a);
	}
	dfs(1);
	if(n%2)
		cout<<-1;
	else
		cout<<ans;
}