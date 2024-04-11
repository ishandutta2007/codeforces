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

pll a[maxn];
ll sm[maxn];
ll ans[maxn];

int main(){
	ll n,A,cf,cm,m;cin>>n>>A>>cf>>cm>>m;
	REP(i,n){
		cin>>a[i].F;
		a[i].S=i;
	}
	sort(a,a+n);
	FOR(i,1,n)
		sm[i]=sm[i-1]+a[i-1].F;
	pair<ll,pll>state1,state2;// score // i // val
	state1=MP((a[0].F*cm),MP(0,a[0].F));
	FOR(i,0,(n-1)){// cnt complete
		ll lft=m-((i*A)-(sm[n]-sm[n-i]));
		if(lft<0)continue;
		ll l=a[0].F,r=A,val=a[0].F;
		while(l<=r){
			ll mid=(l+r)/2;
			pll ppp=MP(mid,-1);
			ll t=upper_bound(a,a+n,ppp)-a;
			t=min(t,n-i);
			ll use=((mid*t)-sm[t]);
			if(lft<use){
				r=mid-1;
			}
			else{
				l=mid+1;
				val=mid;
			}
		}
		state2=MP(((cf*i)+(val*cm)),MP(i,val));
		state1=max(state1,state2);
	}
	if(m>=((n*A)-sm[n])){
		state1=MP((cf*n+cm*A),MP(n,A));
	}
	REP(i,state1.S.F){
		a[n-1-i].F=A;
	}
	pll ppp=MP(state1.S.S,-1);
	ll tl=upper_bound(a,a+n,ppp)-a;
	REP(i,tl)
		a[i].F=state1.S.S;
	REP(i,n)
		ans[a[i].S]=a[i].F;
	cout<<state1.F<<endl;
	REP(i,n)
		cout<<ans[i]<<" ";
}