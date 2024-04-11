// Wanna Hack? GL...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=410,mod=1e9+7;
const ll inf=1e18;

int dp[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    
    dp[1][0]=dp[1][1]=1;
    int n;cin>>n;
    for(int i=2;i<=n;i++){
	dp[i][0]=1;
	for(int j=1;j<=n+1-i;j++){
	    for(int k=0;k<=j;k++)
		dp[i][j]=(1ll*dp[i][j]+1ll*dp[i-1][k]*dp[i-1][j-k])%mod;
	    for(int k=0;k<=j-1;k++)
		dp[i][j]=(1ll*dp[i][j]+1ll*dp[i-1][k]*dp[i-1][j-1-k]+2ll*(k+1)*dp[i-1][k+1] %mod *dp[i-1][j-1-k]+2ll*(j-k)*dp[i-1][k] %mod *dp[i-1][j-k] + 2ll*(k+1)*(j-k)*dp[i-1][k+1] %mod *dp[i-1][j-k])%mod;
	    for(int k=2;k<=j+1;k++)
		dp[i][j]=(1ll*dp[i][j]+2ll*k*(k-1)*dp[i-1][k] %mod *dp[i-1][j+1-k])%mod;		
	}
    }
    return cout<<dp[n][1]<<endl,0;
}