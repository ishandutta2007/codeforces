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

const ll inf=4e18+10;
const ll maxn=1e5+10;
const ll mod=1e9+7;
const ll Big=1e9;

#pragma GCC Optimize("Ofast")

inline bool over_flow(ll a,ll b){
	if(a>=(inf/b))
		return 1;
	return 0;
}
ll Pow(ll a,ll b){
	ll ans=1;
	while(b>0){
		if(b%2){
			if(over_flow(ans,a))
				return inf;
			ans*=a;
		}
		b/=2;
		if(b==0)
			break;
		if(over_flow(a,a))
			return inf;
		a*=a;
	}
	return ans;
}

set<ll>s;
vector<ll>v;

ll lower(ll num){
	ll l=0,r=sz(v)-1,id=-1;
	while(l<=r){
		ll mid=(l+r)/2;
		if(v[mid]<=num){
			id=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return id+1;
}

ll solve(ll L,ll R){
	ll A=sqrt(L),B=sqrt(R);
	if(A*A!=L)
		A++;
	return lower(R)-lower(L-1)+B-A+1;
}

int main(){
	FOR(i,3,61){
		ll j=2;
		ll num=Pow(j,i);
		while(num!=inf){
			ll SQ=sqrt(num);
			if((SQ*SQ)!=num)
				s.insert(num);
			num=Pow(++j,i);
		}
	}
	for(set<ll>::iterator it=s.begin();it!=s.end();it++)
		v.PB(*it);
	ll q;cin>>q;
	while(q--){
		ll l,r;cin>>l>>r;
		cout<<solve(l,r)<<endl;
	}
}