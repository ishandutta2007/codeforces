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

pll f(ll a,ll b){
	if(a==0||b==0)return MP(a,b);
	if(a<2*b&&b<2*a)return MP(a,b);
	if(a>=2*b){
		ll m=a%b;
		ll M=(a-m)/b;
		return f(m+((M%2)*b),b);
	}
	if(b>=2*a){
		ll m=b%a;
		ll M=(b-m)/a;
		return f(a,m+((M%2)*a));
	}
}

int main(){
	ll a,b;cin>>a>>b;
	pll ans=f(a,b);
	cout<<ans.F<<" "<<ans.S;
}