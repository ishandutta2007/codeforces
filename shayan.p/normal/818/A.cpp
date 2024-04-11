// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
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
const ll maxn=2e5+10;

ll lg(ll num){
	ll ans=0;
	while(num>0){
		ans++;
		num/=10;
	}
	return ans;
}
int main(){
	ll n,k;cin>>n>>k;
	ll l=0,r=n;
	ll ans;
	while(l<=r){
		ll mid=(l+r)/2;
		if(lg(mid)+lg(k+1)<15&&mid*(k+1)<=(n/2)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans<<" "<<ans*k<<" "<<n-(ans*(k+1));
}