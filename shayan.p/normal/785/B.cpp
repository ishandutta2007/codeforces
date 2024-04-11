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
const ll mod=1e9+7;
const ll maxn=2e5+10;

ll m1,M1,m2,M2;
int main(){
	ll n;cin>>n;
	m1=inf;m2=inf;
	REP(i,n){
		ll a,b;cin>>a>>b;
		M1=max(M1,a);
		m1=min(m1,b);
	}
	ll m;cin>>m;
	REP(i,m){
		ll a,b;cin>>a>>b;
		M2=max(M2,a);
		m2=min(m2,b);
	}
	ll ans=0;
	ans=max(ans,M2-m1);
	ans=max(ans,M1-m2);
	cout<<ans;
}