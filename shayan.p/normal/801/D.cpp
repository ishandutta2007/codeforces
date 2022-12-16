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
const ll maxn=1010;
const ll mod=1e9+7;

ld dis(pll a,pll b){
	return sqrt(((b.F-a.F)*(b.F-a.F))+((b.S-a.S)*(b.S-a.S)));
}

ld area(pll a,pll b,pll c){
	return (ld(a.F*b.S+b.F*c.S+c.F*a.S-a.S*b.F-b.S*c.F-c.S*a.F)/2);
}

ld  height(pll b,pll a,pll c){//a is the center
	return (area(a,b,c)/dis(b,c));
}

pll p[maxn];
int main(){
	ll n;cin>>n;
	REP(i,n)
		cin>>p[i].F>>p[i].S;
	ld h=height(p[0],p[1],p[2]);
	REP(i,n){
		ll a=i,b=(i+1)%n,c=(i+2)%n;
		h=min(h,height(p[a],p[b],p[c]));
	}
	cout<<setprecision(9)<<fixed<<(h);
}