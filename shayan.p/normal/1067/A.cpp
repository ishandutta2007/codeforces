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

const int maxn=1e5+10,MAX=201,mod=998244353;

ll dp[2][MAX][2];
int a[maxn],n;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
    for(int i=0;i<MAX;i++)
	dp[0][i][0]=1;
    for(int i=1;i<=n;i++){
	int o=i&1,O=1-o;
	memset(dp[o],0,sizeof dp[o]);
	if(a[i]!=-1){
	    dp[o][a[i]][0]=(dp[O][a[i]-1][0]+dp[O][a[i]-1][1])%mod;
	    dp[o][a[i]][1]=(dp[O][MAX-1][1]-dp[O][a[i]-1][1]+dp[O][a[i]][0]-dp[O][a[i]-1][0])%mod;
	}
	else{
	    for(int j=1;j<MAX;j++){
		dp[o][j][0]=(dp[O][j-1][0]+dp[O][j-1][1])%mod;
		dp[o][j][1]=(dp[O][MAX-1][1]-dp[O][j-1][1]+dp[O][j][0]-dp[O][j-1][0])%mod;
	    }
	}
	for(int j=1;j<MAX;j++){
	    dp[o][j][0]=(dp[o][j-1][0]+dp[o][j][0])%mod;
	    dp[o][j][1]=(dp[o][j-1][1]+dp[o][j][1])%mod;
	}
    }
    int ans=dp[n&1][MAX-1][1];
    if(ans<0)ans+=mod;
    printf("%d\n",ans);
    return 0;
}