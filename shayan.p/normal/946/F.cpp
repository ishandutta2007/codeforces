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

const ll maxn=110;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

ll dp[maxn][maxn][maxn][2][2],fib[maxn];

int main(){
	fib[0]=fib[1]=2;
	ll ln,n;cin>>ln>>n;
	string s;cin>>s;
	REP(i,sz(s)){
		if(s[i]=='0')
			dp[0][i][i][0][0]=dp[0][i][i][1][0]=dp[0][i][i][0][1]=dp[0][i][i][1][1]=1;
		else
			dp[1][i][i][0][0]=dp[1][i][i][1][0]=dp[1][i][i][0][1]=dp[1][i][i][1][1]=1;
	}
	FOR(i,2,n){
		fib[i]=(fib[i-1]*fib[i-2])%mod;
		FOR(l,0,ln-1){
			FOR(r,l,ln-1){
				dp[i][l][r][0][0]=(dp[i-1][l][r][0][0]+dp[i-2][l][r][0][0])%mod;
				dp[i][l][r][0][1]=(((dp[i-1][l][r][0][1]*fib[i-2])%mod)+dp[i-2][l][r][0][1])%mod;
				dp[i][l][r][1][0]=(dp[i-1][l][r][1][0]+((dp[i-2][l][r][1][0]*fib[i-1])%mod))%mod;
				dp[i][l][r][1][1]=(((dp[i-1][l][r][1][1]*fib[i-2])%mod)+((dp[i-2][l][r][1][1]*fib[i-1])%mod))%mod;
				FOR(k,l+1,r){
					dp[i][l][r][0][0]=(dp[i][l][r][0][0]+((dp[i-1][l][k-1][0][0]*dp[i-2][k][r][0][0])%mod))%mod;
					dp[i][l][r][0][1]=(dp[i][l][r][0][1]+((dp[i-1][l][k-1][0][0]*dp[i-2][k][r][0][1])%mod))%mod;
					dp[i][l][r][1][0]=(dp[i][l][r][1][0]+((dp[i-1][l][k-1][1][0]*dp[i-2][k][r][0][0])%mod))%mod;
					dp[i][l][r][1][1]=(dp[i][l][r][1][1]+((dp[i-1][l][k-1][1][0]*dp[i-2][k][r][0][1])%mod))%mod;
				}
			}
		}
	}
	cout<<dp[n][0][ln-1][1][1];
}