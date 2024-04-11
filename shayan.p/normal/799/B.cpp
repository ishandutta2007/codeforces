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

set<pll>A[4],B[4];
ll p[maxn],a[maxn],b[maxn];

int main(){
	ll n;cin>>n;
	REP(i,n)
		cin>>p[i];
	REP(i,n)
		cin>>a[i];
	REP(i,n)
		cin>>b[i];
	REP(i,n){
		A[a[i]].insert(MP(p[i],i));
		B[b[i]].insert(MP(p[i],i));
	}
	vector<ll>ans;
	ll m;cin>>m;
	REP(i,m){
		ll c;cin>>c;
		pll aa=MP(inf,inf),bb=MP(inf,inf);
		if(sz(A[c]))aa=*A[c].begin();
		if(sz(B[c]))bb=*B[c].begin();
		
		pll mn=min(aa,bb);
		ans.PB((mn.F==inf?-1:mn.F));
		if(mn.F==inf)
			continue;
		A[a[mn.S]].erase(mn);
		B[b[mn.S]].erase(mn);
	}
	REP(i,sz(ans))
		cout<<ans[i]<<" ";
}