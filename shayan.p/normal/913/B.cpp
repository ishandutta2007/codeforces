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
const ll mod=1e9+7;
const ll maxn=1010;

vector<ll>v[maxn];

inline bool leaf(ll u){
	return (sz(v[u])==0);
}

bool dfs(ll u){
	if(leaf(u))return 1;
	ll num=0;
	REP(i,sz(v[u])){
		ll y=v[u][i];
		num+=leaf(y);
		if(!dfs(y))
			return 0;
	}
	if(num>=3)
		return 1;
	return 0;
}

int main(){
	ll n;cin>>n;
	FOR(i,2,n){
		ll x;cin>>x;
		v[x].PB(i);
	}
	if(dfs(1))
		cout<<"Yes";
	else
		cout<<"No";
}