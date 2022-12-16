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
const ll maxn=1010;
const ld eps=0.0000001;
#pragma GCC Optimize("Ofast")

ld dp[maxn];
ll ans[maxn];

int main(){
	ll k,q;cin>>k>>q;
	dp[0]=1;
	ll last=0;
	FOR(d,1,inf){// while true
		FORD(j,k,1)
			dp[j]=(dp[j]*(ld(j)/ld(k)))+(dp[j-1]*(ld(k-j+1)/ld(k)));
		dp[0]=0;
		while(last<=1000&&dp[k]>((ld(last)-eps)/ld(2000))){
			ans[last]=d;
			last++;
		}
		if(last>1000)
			break;
	}
	REP(i,q){
		ll p;cin>>p;
		cout<<ans[p]<<endl;
	}
}