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

ll a[6];
int main(){
	ll n;cin>>n;
	REP(i,n){
		ll x;cin>>x;
		a[--x]++;
	}
	REP(i,n){
		ll x;cin>>x;
		a[--x]--;
	}
	ll ans=0;
	REP(i,5){
		if(abs(a[i])%2!=0){
			cout<<-1;
			return 0;
		}
		ans+=abs(a[i])/2;
	}
	cout<<ans/2;
}