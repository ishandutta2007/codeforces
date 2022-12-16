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

const ll inf=4e18;
const ll mod=1e9+7;
const ll maxn=2e5+10;

ll p[maxn];

int main(){
	ll n,k,ans=0;
	cin>>n>>k;
	REP(i,n)
		cin>>p[i];
	REP(i,n){
		ll x;cin>>x;
		ans+=x;
		p[i]-=x;
	}
	sort(p,p+n);
	REP(i,k)
		ans+=p[i];
	FOR(i,k,n-1)
		ans+=min(p[i],ll(0));
	cout<<ans;
}