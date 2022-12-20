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

map<ll,ll>mp;

ll C(ll n,ll k){
	ll ans=1;
	REP(i,k){
		ans*=n-i;
	}
	FOR(i,1,k){
		ans/=i;
	}
	return ans;
}
int main(){
	ll n;cin>>n;
	REP(i,n){
		ll x;cin>>x;
		mp[x]++;
	}
	map<ll,ll>::iterator it=mp.begin();
	stack<pll>s;
	ll remain=3;
	while(remain){
		ll m=min(remain,it->S);
		remain-=m;
		s.push(MP(it->S,m));
		it++;
	}
	ll z=1;
	while(!s.empty()){
		z*=C(s.top().F,s.top().S);
		s.pop();
	}
	cout<<z;
}