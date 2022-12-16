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

int main(){
	ll t;cin>>t;
	REP(i,t){
		ll n,k;cin>>n>>k;
		ll tmp=0,ans;
		REP(j,k){
			ll x;cin>>x;
			if(tmp==0)
				ans=x;
			ll num=x-tmp+1;
			ans=max(ans,(num/2)+(num%2));
			tmp=x;
		}
		ans=max(ans,n-tmp+1);
		cout<<ans<<endl;
	}
}