#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 202;
int n, k;
char s[N],t[N];
int dp[N][N][N];
int p1[N], p2[N];
void upd(int &x,int y){
	x=max(x,y);
}
int main() {
	scanf("%d%d",&n,&k);
	scanf("%s%s",s+1,t+1);

	for(int i=1;i<=n;i++)
		p1[i]=p1[i-1]+(s[i]==t[1]);
	for(int i=1;i<=n;i++)
		p2[i]=p2[i-1]+(s[i]==t[2]);
	
	if (t[1] == t[2]) {
		int has=p1[n];
		has+=k;
		has=min(has,n);
		printf("%d\n", has*(has-1)/2);
		return 0;
	}

	for(int i=0;i<N;i++)for(int j=0;j<N;j++)for(int x=0;x<N;x++)dp[i][j][x]=-1e9;
	dp[0][0][0]=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			for(int x=0;x<=k;x++){
				//if(dp[i][j][x]>0)
				//printf("dp[%d][%d][%d]=%d\n", i,j,x,dp[i][j][x]);
				if(s[i+1]==t[1]){
					upd(dp[i+1][j+1][x],dp[i][j][x]);
				}
				if(s[i+1]==t[2]){
					upd(dp[i+1][j][x],dp[i][j][x]+j);
				}
				upd(dp[i+1][j+1][x+1],dp[i][j][x]);
				upd(dp[i+1][j][x+1],dp[i][j][x]+j);
				upd(dp[i+1][j][x],dp[i][j][x]);
			}	
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=k;j++)
			ans=max(ans,dp[n][i][j]);
	printf("%d\n", ans);
}