// Faster!

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

const int maxn=155,maxn2=maxn*maxn / 2,inf=1e9;

int dp[2][maxn][maxn2],a[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k,s;cin>>n>>k>>s;
    s=min(s,(n*(n-1))/2);
    for(int i=1;i<=n;i++){
	cin>>a[i];
    }
    for(int i=1;i<=n;i++){
	int o=i&1,O=1-o;
	for(int j=1;j<=k && j<=i;j++){
	    for(int w=0;w<=s;w++){
		dp[o][j][w]=inf;
		if(j<i) dp[o][j][w]=dp[O][j][w];
		if(i-j<=w) dp[o][j][w]=min(dp[o][j][w],a[i]+dp[O][j-1][w-i+j]);
	    }
	}
    }
    return cout<<dp[n&1][k][s]<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.