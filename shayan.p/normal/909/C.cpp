#include<bits/stdc++.h>
#define PB push_back
#define PF push_front
#define POF pop_front
#define POB pop_back
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)
#define REP(i,a) for(ll i=0;i<a;i++)
#define REPD(i,a) for(ll i=a-1;i>=0;i--)
#define MP make_pair
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll ind=1e18;
const ll maxn=5e3+10;
const ll mod=1e9+7;

ll dp[maxn][maxn];

int main(){
	ll n;cin>>n;
	dp[0][0]=1;
	char ch='s';
	FOR(i,1,n){
		if(ch=='s'){
			dp[i][n]=dp[i-1][n];
			REPD(j,n)
				dp[i][j]=(dp[i-1][j]+dp[i][j+1])%mod;
		}
		if(ch=='f'){
			FORD(j,n,1){
				dp[i][j]=dp[i-1][j-1]%mod;
			}
		}
		cin>>ch;
	}
	ll sum=0;
	FOR(i,0,n){
		sum+=dp[n][i];
		sum%=mod;
	}
	cout<<sum;
	return 0;
}