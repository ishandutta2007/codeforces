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

const int maxn=510,mod=1e9+7;
const ll inf=1e18;

ll dp[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int r=3;r<=n;r++){
	for(int l=r-2;l>=1;l--){
	    dp[l][r]=inf;
	    for(int k=l+1;k<r;k++){
		dp[l][r]=min(dp[l][r],dp[l][k]+dp[k][r]+1ll*l*r*k);
	    }
	}
    }
    return cout<<dp[1][n]<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.