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

map<string,ll>mp;
ll g[maxn];
ll mn[maxn];
ll a[maxn];

int main(){
	ll n,k,m;cin>>n>>k>>m;
	FOR(i,1,n){
		string s;cin>>s;
		mp[s]=i;
	}
	FOR(i,1,n){
		cin>>a[i];
	}
	FOR(i,1,k){
		ll x;cin>>x;
		ll MN=inf;
		REP(j,x){
			ll num;cin>>num;
			g[num]=i;
			MN=min(MN,a[num]);
		}
		mn[i]=MN;
	}
	ll ans=0;
	REP(i,m){
		string s;cin>>s;
		ans+=mn[g[mp[s]]];
	}
	cout<<ans;
}