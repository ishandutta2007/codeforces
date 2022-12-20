// Jump, and you will find out how to unfold your wings as you fall.

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

const int maxn=410,inf=1e9;

int dp[2][maxn][maxn],tot[maxn][maxn],ans[maxn],v[maxn],a[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
	cin>>v[i];
    }
    for(int i=1;i<=n;i++){
	cin>>a[i];
    }
    for(int r=1;r<=n;r++){
	tot[r][r]=v[1];
	for(int l=r-1;l>=1;l--){
	    dp[0][l][r]=dp[1][l][r]=tot[l][r]=-inf;
	    if(a[l]<a[r] && a[r]-a[l]==1) dp[0][l][r]=tot[l+1][r-1];
	    if(a[l]>a[r] && a[l]-a[r]==1) dp[1][l][r]=tot[l+1][r-1];
	    for(int k=l+1;k<r;k++){
		if(a[l]<a[k] && a[k]<a[r]) dp[0][l][r]=max(dp[0][l][r],dp[0][l][k]+dp[0][k][r]);
		if(a[l]>a[k] && a[k]>a[r]) dp[1][l][r]=max(dp[1][l][r],dp[1][l][k]+dp[1][k][r]);
	    }
	    for(int k=l;k<=r;k++){
		if(a[k]>=a[l] && a[k]>=a[r] && 2*a[k]-a[l]-a[r]+1<=n)
		    tot[l][r]=max(tot[l][r],dp[0][l][k]+dp[1][k][r]+v[2*a[k]-a[l]-a[r]+1]);
	    }
	    for(int k=l;k<r;k++){
		tot[l][r]=max(tot[l][r],tot[l][k]+tot[k+1][r]);
	    }
	}
    }
    for(int i=1;i<=n;i++){
	ans[i]=ans[i-1];
	for(int j=1;j<=i;j++)
	    ans[i]=max(ans[i],tot[j][i]+ans[j-1]);
    }
    return cout<<ans[n]<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.