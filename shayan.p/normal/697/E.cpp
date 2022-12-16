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

pll gcd(ll a,ll b){
	if(b==0) return MP(a,0);
	pll p=gcd(b,a%b);
	return MP(p.S,p.F-((a/b)*p.S));
}
ll inv(ll a) {
	return (gcd(a,mod).F+mod)%mod;
}

ll tavan(ll a,ll b){
	if(b==0)return 1;
	a%=mod;
	return ((b%2?a:1)*(tavan(a*a,b/2)))%mod;
}

int main(){
	bool par=1;
	ll k;cin>>k;
	ll t=1;
	REP(i,k){
		ll x;cin>>x;
		par&=(x%2);
		x%=(mod-1);
		t=(t*x)%(mod-1);
	}
	t=(t-1+mod-1)%(mod-1);
	ll num1=tavan(2,t);
	ll num2=num1;
	if(par)
		num1--;
	else
		num1++;
	num1*=inv(3);
	num1%=mod;
	cout<<num1<<"/"<<num2;
}