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
typedef pair<ld,ld> pld;

const ll inf=4e18;
const ll maxn=1e5+10;
const ll mod=1e9+7;
const ld pi=3.1415926535897932;

#pragma GCC Optimize("Ofast")

inline ld t(ld a){
	return a*a;
}
inline ld dis(pld a,pld b){
	return sqrt(t(a.F-b.F)+t(a.S-b.S));
}
inline ld dis2(pld a,pld b){
	return (t(a.F-b.F)+t(a.S-b.S));
}
inline ld area2(pld a,pld b,pld c){
	return abs((a.F*b.S)+(b.F*c.S)+(c.F*a.S)-(a.F*c.S)-(b.F*a.S)-(c.F*b.S));
}
pld pt[maxn];

int main(){
	ll n;cin>>n;
	pld p;cin>>p.F>>p.S;
	ld mn=inf,mx=-inf;
	REP(i,n){
		cin>>pt[i].F>>pt[i].S;
		ld ds=dis(p,pt[i]);
		mn=min(mn,ds);
		mx=max(mx,ds);
	}
	REP(i,n){
		ll j=(i+1)%n;
		ld BC=dis2(pt[i],pt[j]);
		ld AB=dis2(pt[i],p);
		ld AC=dis2(pt[j],p);
		if((BC+AB)<AC)continue;
		if((BC+AC)<AB)continue;
		ld ds=(area2(pt[i],pt[j],p))/dis(pt[i],pt[j]);
		mn=min(mn,ds);
	}
	cout<<setprecision(9)<<fixed<<(t(mx)-t(mn))*pi;
}