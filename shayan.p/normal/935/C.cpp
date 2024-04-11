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
typedef pair<ld,ld> pld;

const ll inf=4e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

inline ld t(ld a){
	return a*a;
}
ld dis(pld a,pld b){
	return sqrt(t(a.F-b.F)+t(a.S-b.S));
}

int main(){
	ld R,x1,y1,x2,y2;cin>>R>>x1>>y1>>x2>>y2;
	if(dis(MP(x1,y1),MP(x2,y2))>=R){
		cout<<x1<<" "<<y1<<" "<<R;
		return 0;
	}
	if(x1==x2&&y1==y2){
		cout<<setprecision(9)<<fixed<<x1+(R/2)<<" "<<y1<<" "<<R/2;
		return 0;
	}
	ld x=-x2+x1,y=-y2+y1;
	ld k=sqrt(t(R)/(t(x)+t(y)));
	ld px=x1+k*x,py=y1+k*y;
	ld r=dis(MP(px,py),MP(x2,y2))/ld(2);
	px=(px+x2)/2;py=(py+y2)/2;
	cout<<setprecision(9)<<fixed<<px<<" "<<py<<" "<<r;
}