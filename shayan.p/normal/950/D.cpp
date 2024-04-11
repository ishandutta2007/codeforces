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

const ll inf=1e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

struct solve{
	ll solve2(ll n,ll x){
		if(x==1)
			return solve1(n,n);
		else
			return solve1(n,x-1);
	}
	ll solve1(ll n,ll x){
		if(x%2)
			return (x/2)+1;
		if(n%2)
			return (n/2)+1+solve2(n/2,x/2);
		else
			return (n/2)+solve1(n/2,x/2);
	}
};solve slv;

int main(){
	ll n,q;cin>>n>>q;
	while(q--){
		ll x;cin>>x;
		cout<<slv.solve1(n,x)<<endl;
	}
}