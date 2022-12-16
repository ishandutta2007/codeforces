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
typedef pair<pll,ll> pl3;

const ll maxn=1e5+10;

pl3 p[maxn];

int main(){
	ll n;cin>>n;
	REP(i,n)
		cin>>p[i].F.F;
	REP(i,n)
		cin>>p[i].F.S;
	REP(i,n)
		p[i].S=i+1;
	sort(p,p+n,greater<pl3>());
	vector<ll>ans;
	REP(i,(n/2)+1){
		ll a=max(2*i-1,(ll)0);
		ll b=min(2*i,n);
		if(p[a].F.S<p[b].F.S)
			ans.PB(p[b].S);
		else
			ans.PB(p[a].S);
	}
	cout<<sz(ans)<<endl;
	REP(i,sz(ans)){
		cout<<ans[i]<<" ";
	}
}