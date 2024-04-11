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

const int maxn=102,mod=1e9+7;
const ll inf=1e18;

ll a[maxn];
ll dp[maxn][maxn][maxn][2],ans[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    string s;cin>>s;
    for(int i=1;i<=n;i++){
	cin>>a[i];
    }
    for(int i=0;i<maxn;i++){
	for(int j=0;j<maxn;j++){
	    ans[i][j]=-inf;
	    for(int k=0;k<maxn;k++)
		dp[i][j][k][0]=dp[i][j][k][1]=-inf;
	}
    }
    for(int r=0;r<n;r++){
	ans[r][r]=a[1];
	dp[r][r][1][s[r]-'0']=0;
	dp[r][r][0][0]=dp[r][r][0][1]=ans[r][r];
	for(int l=r-1;l>=0;l--){
	    for(int k=1;k<=r-l+1;k++){
		dp[l][r][k][s[l]-'0']=dp[l+1][r][k-1][s[l]-'0'];
		for(int w=l+1;w<=r;w++){
		    dp[l][r][k][0]=max(dp[l][r][k][0],ans[l][w-1]+dp[w][r][k][0]);
		    dp[l][r][k][1]=max(dp[l][r][k][1],ans[l][w-1]+dp[w][r][k][1]);
		}
		ans[l][r]=max(ans[l][r],a[k]+max(dp[l][r][k][0],dp[l][r][k][1]));
	    }
	    dp[l][r][0][0]=dp[l][r][0][1]=ans[l][r];
	}
    }
    return cout<<ans[0][n-1]<<endl,0;
}