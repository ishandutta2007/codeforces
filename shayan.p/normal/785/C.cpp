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
const ll big=(1e9)+(5e8);
int main(){
	ll n,m;cin>>n>>m;
	if(n<=m){
		cout<<n;
		return 0;
	}
	ll l=0,r=big,ans;
	while(l<=r){
		ll mid=(l+r)/2;
		ll num=(mid*(mid-1))/2;
		if((num+mid+m)>=n){
			ans=mid+m;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	cout<<ans;
}