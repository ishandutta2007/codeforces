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

inline ll f(ll a,ll b){
	ll num1=(b*(b+1))/2,num2=(a*(a+1))/2;
	return num1*(a+1)+num2*(b+1);
}
ll ans;
int main(){
	ll m,b;cin>>m>>b;
	REP(i,b){
		ll A=i;
		ll B=m*(b-i);
		ans=max(ans,f(A,B));
	}
	cout<<ans;
}