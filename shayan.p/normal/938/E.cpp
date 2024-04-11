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
const ll maxn=1e6+10;
const ll mod=1e9+7;

ll a[maxn];
ll sm,ans;
map<ll,ll>mp;

pll gcd(ll a,ll b){
	if(b==0) return MP(a,0);
	pll p=gcd(b,a%b);
	return MP(p.S,p.F-((a/b)*p.S));
}
ll inv(ll a) {
	return (gcd(a,mod).F+mod)%mod;
}

int main(){
	ll n;cin>>n;
	REP(i,n){
		ll x;cin>>x;
		mp[x]++;
	}
	map<ll,ll>::iterator befend=--mp.end();
	for(map<ll,ll>::iterator it=mp.begin();it!=befend;it++){
		ans=(ans+(((((it->F)*(it->S))%mod)*inv(n-sm))%mod))%mod;
		sm+=it->S;
	}
	FOR(i,1,n)
		ans=(ans*i)%mod;
	cout<<ans;
}