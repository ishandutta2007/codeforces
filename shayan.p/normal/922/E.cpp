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
const ll maxn=1010;
const ll maxc=10010;

#pragma GCC Optimize("Ofast")

ll c[maxn];
ll cost[maxn];
ll dp[maxn][maxc];

int main(){
	REP(i,maxn)
		REP(j,maxc)
			dp[i][j]=-1;
			
	ll n,w,b,x;cin>>n>>w>>b>>x;
	REP(i,n)
		cin>>c[i];
	REP(i,n)
		cin>>cost[i];
		
	dp[0][0]=w;
	FOR(i,1,c[0]){
		if(dp[0][i-1]>=cost[0])
			dp[0][i]=dp[0][i-1]-cost[0];
	}
	ll sum=c[0];
	
	FOR(i,1,n-1){
		dp[i][0]=w;
		sum+=c[i];
		FOR(j,1,sum){
			FOR(k,0,c[i]){
				if(dp[i-1][j-k]==-1)
					continue;
				ll num=min(dp[i-1][j-k]+x,w+((j-k)*b))-(k*cost[i]);
				if(num>=0)
					dp[i][j]=max(dp[i][j],num);
			}
		}
	}
	FORD(i,maxc-1,0){
		if(dp[n-1][i]!=-1){
			cout<<i;
			return 0;
		}
	}
}