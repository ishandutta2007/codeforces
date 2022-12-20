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

const ll inf=1e15;
const ll maxn=1e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

struct point{
	ll x,y;
	void get(){
		cin>>x>>y;
	}
};point a,b,t,p;

inline ld pw(ld d){
	return d*d;
}
ld dis(point a,point b){
	return sqrt(pw(a.x-b.x)+pw(a.y-b.y));
}

vector<pair<ld,ll> > Min[2];
ld c=0;

int main(){
	a.get();b.get();t.get();
	ll n;cin>>n;
	REP(i,n){
		p.get();
		c+=2*(dis(t,p));
		Min[0].PB(MP(dis(a,p)-dis(p,t),i));
		Min[1].PB(MP(dis(b,p)-dis(p,t),i));
	}
	sort(Min[0].begin(),Min[0].end());
	sort(Min[1].begin(),Min[1].end());
	ld ans1,ans2,ans3;
	ans1=c+Min[0][0].F;
	ans2=c+Min[1][0].F;
	if(n==1)
		ans3=inf;
	else{
		if(Min[0][0].S!=Min[1][0].S){
			ans3=c+Min[0][0].F+Min[1][0].F;
		}
		else{
			ans3=c+Min[0][0].F+Min[1][1].F;
			ans3=min(ans3,c+Min[0][1].F+Min[1][0].F);
		}
	}
	ld ans=min(ans3,min(ans1,ans2));
	cout<<setprecision(9)<<fixed<<ans;
}