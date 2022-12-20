// Can U hack it?

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

const int mod=1e9+7;

int main(){
    int n,m,x;scanf("%d%d%d",&n,&m,&x);
    if(n>m){
	printf("0\n");
	return 0;
    }
    int dp[m+10][n+10][n+10];
    memset(dp,0,sizeof dp);
    dp[0][0][0]=1;
    for(int i=1;i<=m;i++){
	for(int l=0;l<=n;l++){
	    for(int r=0;r<=l;r++){
		ll DP=0;
		if(l>0 && r>0) DP+=dp[i-1][l-1][r-1];
		if(l>0) DP+=dp[i-1][l-1][r];
		if(r>0 && i!=x) DP+=dp[i-1][l][r-1];
		if(i!=x) DP+=dp[i-1][l][r];
		dp[i][l][r]=DP%mod;
	    }
	}
    }
    int ans=dp[m][n][n];
    for(int i=1;i<=n;i++)
	ans=1ll*ans*i %mod;
    printf("%d\n",ans);
}