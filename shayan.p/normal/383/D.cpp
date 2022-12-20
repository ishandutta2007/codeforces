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
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=1e3+10;
const ll MAX=1e4+10;
const ll mod=1e9+7;

ll dp[maxn][MAX];
ll ans;
ll a[maxn];

int main(){
	ll n;cin>>n;
	REP(i,n)
		cin>>a[i];
	dp[0][a[0]]=1;
	FOR(i,1,n-1){
		REP(j,MAX)
			dp[i][j]=(dp[i-1][abs(j-a[i])]+dp[i-1][j+a[i]])%mod;
		dp[i][a[i]]++;
		ans=(ans+dp[i][0])%mod;
	}
	cout<<ans;
}