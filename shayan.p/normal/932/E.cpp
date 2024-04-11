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

#define bug(i) cerr<<i<<endl;

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=5010;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

ll dp[maxn][maxn];

ll pw(ll a,ll b){
	ll ans=1;
	while(b>0){
		if(b%2)
			ans=(ans*a)%mod;
		a=(a*a)%mod;
		b/=2;
	}
	return ans;
}
ll P(ll n,ll k){
	ll ans=1;
	REP(i,k)
		ans=(ans*(n-i))%mod;
	return ans;
}

int main(){
	ll n,k;cin>>n>>k;
	dp[0][0]=1;
	FOR(i,1,k)
		FOR(j,1,k)
			dp[i][j]=((dp[i-1][j]*j)+(dp[i-1][j-1]))%mod;
	ll ans=0;
	// sum i=1->n C(n,i)*(i^k) == tedad rah hayii ke toop ha ro toye i ta daste moshakhas bezarim == sum i=1->k dp[k][i]*C(n,i)*(i!)* 2 ^ n-i
	FOR(i,1,k)
		ans=(ans+(((dp[k][i]*P(n,i))%mod)*pw(2,n-i))%mod)%mod;
	cout<<ans;
}