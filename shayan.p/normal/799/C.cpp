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
const ll mod=1e9+7;
const ll maxn=2e5+10;

#pragma GCC Optimize("Ofast")

ll mx[maxn];

ll leq(vector<pll>&v,ll num){// less or equal
	ll l=0,r=sz(v)-1,id=-1;
	while(l<=r){
		ll mid=(l+r)/2;
		if(v[mid].F<=num){
			id=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return id;
}
ll ans1(vector<pll>&C,ll c){
	if(sz(C)<2)return 0;
	ll ans=0;
	REP(i,sz(C)){
		ll bef=(i==0?0:mx[i-1]);
		mx[i]=max(C[i].S,bef);
	}
	FORD(i,(sz(C)-1),1){
		ll bef=min(i-1,leq(C,c-C[i].F));
		if(0<=bef&&bef<sz(C))
			ans=max(ans,C[i].S+mx[bef]);
	}
	return ans;
}
ll ans2(vector<pll>&C,vector<pll>&D,ll c,ll d){
	ll mxc=0,mxd=0;
	REP(i,sz(C))
		if(C[i].F<=c)
			mxc=max(mxc,C[i].S);
	REP(i,sz(D))
		if(D[i].F<=d)
			mxd=max(mxd,D[i].S);
	if(mxc==0||mxd==0)return 0;
	return mxc+mxd;
}

int main(){
	ll n,c,d;cin>>n>>c>>d;
	vector<pll>C,D;
	REP(i,n){
		ll b,p;cin>>b>>p;
		char ch;cin>>ch;
		if(ch=='C')
			C.PB(MP(p,b));// pb not bp
		else
			D.PB(MP(p,b));
	}
	sort(C.begin(),C.end());
	sort(D.begin(),D.end());
	cout<<max(ans2(C,D,c,d),max(ans1(C,c),ans1(D,d)));
}