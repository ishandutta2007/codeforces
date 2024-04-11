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
const ll Big=1e14;
const ll maxn=2e5+10;

bool pos(ll num,ll t,ll k){
	if(((num/t)+((num%t)>=((t/2)+(t%2))))>=k)return 1;
	return 0;
}
int main(){
	ll n,k;cin>>n>>k;
	ll sum=0;
	REP(i,n){
		ll x;cin>>x;
		sum+=x;
	}
	ll l=0,r=Big,ans;
	while(l<=r){
		ll mid=(l+r)/2;
		if(pos(sum+mid*k,mid+n,k)){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	cout<<ans;
}