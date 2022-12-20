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

const ll maxn=21;

ll dp[maxn][maxn][5][2];// n // t // now // decreasing?0 increasing?1

int main(){
	ll n,t;cin>>n>>t;
	dp[2][0][2][1]=1;
	dp[2][0][3][1]=2;
	dp[2][0][4][1]=3;
	
	dp[2][0][2][1]=1;
	dp[2][0][3][1]=2;
	dp[2][0][4][1]=3;
	dp[3][0][3][1]=1;
	dp[3][0][4][1]=3;
	dp[4][0][4][1]=1;
	FOR(i,3,n){
		FOR(j,1,t){
			FOR(now,1,4){
				FOR(bef,1,(now-1))
					dp[i][j][now][1]+=dp[i-1][j][bef][1]+dp[i-1][j][bef][0];
				FOR(bef,now+1,4)
					dp[i][j][now][0]+=dp[i-1][j-1][bef][1]+dp[i-1][j][bef][0];
			}
		}
	}
	ll sm=0;
	FOR(i,1,4)
		sm+=dp[n][t][i][0];
	cout<<sm;
}