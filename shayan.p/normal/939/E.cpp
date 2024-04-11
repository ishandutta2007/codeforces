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
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

vector<ll>sm,a;

ld val(ll ind){
	return ld(sm[ind]+a.back())/ld(ind+2);
}

/*
ld ternary(){
	if(sz(sm)==1)
		return ld(sm.back());
	if(sz(sm)==2)
		return ld(sm.back())/ld(2);
	ll l=0,r=sz(sm)-2;
	vector<pair<ld,ll> >vec;
	while(l<r){
		if(r-l==1)
			return min(val(l),val(r));
		if(r-l==2)
			return min(val(l),min(val(l+1),val(l+2)));
		ll mid1=l+(r-l)/3;
		ll mid2=mid1+(r-l)/3;
		vec.clear();
		vec.PB(MP(val(l),l));vec.PB(MP(val(mid1),mid1));vec.PB(MP(val(mid2),mid2));vec.PB(MP(val(r),r));
		sort(vec.begin(),vec.end());
		ll a=vec[0].S,b=vec[1].S;
		l=min(a,b);r=max(a,b);
	}
	return val(l);
}
*/

ld ternary(){
	if(sz(sm)==1)
		return ld(sm.back());
	if(sz(sm)==2)
		return ld(sm.back())/ld(2);
	ll l=0,r=sz(sm)-2;
	while(l<r){
		if(r-l==1)
			return min(val(l),val(r));
		if(r-l==2)
			return min(val(l),min(val(l+1),val(l+2)));
		ll mid=(l+r)/2;
		if(val(mid)<val(mid+1))
			r=mid;
		else
			l=mid;
	}
	return val(l);
}

int main(){
	ll q;cin>>q;
	ld ans=0;
	REP(i,q){
		ll task,x;cin>>task;
		if(task==1){
			cin>>x;
			if(sz(a))
				sm.PB(x+sm.back());
			else
				sm.PB(x);
			a.PB(x);
			ans=max(ans,ld(x)-ternary());
		}
		else{
			cout<<setprecision(10)<<fixed<<ans<<endl;
//			cout<<setprecision(8)<<fixed<<ternary()<<endl;
		}
	}
}