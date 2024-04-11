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

inline ll f(ll num){
	ll a=num,b=num-1;
	if(num%2)b/=2;
	else a/=2;
	return a*b;
}
int main(){
	ll q;cin>>q;
	REP(i,q){
		ll n,ans;cin>>n;
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		ll l=0,r=n-1;
		while(l<=r){
			ll mid=(l+r)/2;
			if(2*mid<=f(n-mid)+mid){
				ans=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		cout<<max(min(2*ans,f(n-ans)+ans),min(2*(ans+1),f(n-ans-1)+ans+1))<<endl;
	}
}