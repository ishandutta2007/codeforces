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
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)
#define Bug(num) cout<<"here "<<num<<endl;

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=110;
const ll mod=1e9+7;
const ll inf=4e18;

ll dp[maxn][3];

int main(){
	ll n;cin>>n;
	FOR(i,1,n){
		ll x;cin>>x;
		dp[i][0]=min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2])+1;
		if(bit(x,0)) dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
		else dp[i][1]=inf;
		if(bit(x,1)) dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
		else dp[i][2]=inf;
	}
	cout<<min(min(dp[n][0],dp[n][1]),dp[n][2]);
}