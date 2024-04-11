#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000 + 10;
int t,n,m,r[N],b[N],sr[N],sb[N];
int dp[N][N];
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n); for(int i=1;i<=n;i++) {
			scanf("%d",&r[i]); sr[i]=sr[i-1]+r[i];
		}
		scanf("%d",&m); for(int i=1;i<=m;i++) {
			scanf("%d",&b[i]); sb[i]=sb[i-1]+b[i];
		}

		for(int i=0;i<=n;i++)for(int j=0;j<=m;j++) dp[i][j]=-1e9;
		dp[0][0]=0;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				if(i+1<=n)
					dp[i+1][j]=max(dp[i+1][j], max(dp[i][j],sr[i+1]+sb[j]));
				if(j+1<=m)
					dp[i][j+1]=max(dp[i][j+1], max(dp[i][j],sr[i]+sb[j+1]));
			}
		}
		printf("%d\n", dp[n][m]);
	}
}