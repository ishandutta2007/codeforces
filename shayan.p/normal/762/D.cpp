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

const ll inf=1e18;
const ll mod=1e9+7;
const ll maxn=1e5+10;

ll dp[3][maxn];
ll a[3][maxn];

int main(){
	ll n;cin>>n;
	REP(i,3)
		REP(j,n)
			cin>>a[i][j];
	dp[2][n-1]=a[2][n-1];
	dp[1][n-1]=a[2][n-1]+a[1][n-1];
	dp[0][n-1]=a[2][n-1]+a[1][n-1]+a[0][n-1];
	FORD(i,n-2,0){
		ll A,B,C,D;
		A=(a[0][i]+dp[0][i+1]);
		B=(a[0][i]+a[1][i]+dp[1][i+1]);
		C=(a[0][i]+a[1][i]+a[2][i]+dp[2][i+1]);
		D=a[0][i]+a[0][i+1]+a[1][i]+a[1][i+1]+a[2][i]+a[2][i+1]+dp[2][i+2];
		dp[0][i]=max(A,max(B,max(C,D)));
		A=a[1][i]+dp[1][i+1];
		B=a[1][i]+a[2][i]+dp[2][i+1];
		C=a[1][i]+a[0][i]+dp[0][i+1];
		dp[1][i]=max(A,max(B,C));
		A=(a[2][i]+dp[2][i+1]);
		B=(a[2][i]+a[1][i]+dp[1][i+1]);
		C=(a[2][i]+a[1][i]+a[0][i]+dp[0][i+1]);
		D=a[0][i]+a[0][i+1]+a[1][i]+a[1][i+1]+a[2][i]+a[2][i+1]+dp[0][i+2];
		dp[2][i]=max(A,max(B,max(C,D)));
	}
	cout<<dp[0][0];
}