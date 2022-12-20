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
const ll maxn=1e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

ll a[maxn];
ll sm=0;

int main(){
	ll n;cin>>n;
	REP(i,n)
		cin>>a[i];
	ll s,f;cin>>s>>f;
	s--;f--;
	ll len=f-s;
	REP(i,len)
		sm+=a[i];
	ll mx=sm,mxind=0;
	ll ans=s+1;
	FOR(i,1,n-1){
		sm-=a[i-1];sm+=a[(i+len-1)%n];
		if(mx<=sm){
			mxind=i;
			ll num=(((s-mxind)+(3*n))%n)+1;
			if(mx==sm)
				ans=min(ans,num);
			else
				ans=num;
			mx=sm;
		}
	}
	cout<<ans;
}