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

#pragma GCC Optimize("Ofast")

pll fix;
ll zarb;
ll x,p;

pll GCD(ll a,ll b){
	if(b==0) return MP(a,0);
	pll p=GCD(b,a%b);
	return MP(p.S,p.F-((a/b)*p.S));
}

ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}

ll combine(ll a,ll b){
	ll num=((b-a)*p)+a;
	return (num+zarb)%zarb;
}

ll cnt(ll num){
	return (x/zarb)+(num<=(x%zarb));
}

int main(){
	ll a,b;cin>>a>>b>>p>>x;
	fix=GCD(p,p-1);
	zarb=p*(p-1);
	ll an=1,ans=0;
	REP(i,p-1){
		ll N=(GCD(an,p).F*(b/(gcd(an,p))));
		N=((N%p)+p)%p;
		ans+=cnt(combine(N,i));
		an=(an*a)%p;
	}
	cout<<ans;
}