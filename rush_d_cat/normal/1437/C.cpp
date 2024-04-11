#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200 + 10;
int T,n,t[N],dp[N<<1][N];
const int inf=1e9;
void upd(int &x,int y){
	x=min(x,y);
}
int main() {
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&t[i]);
		sort(t+1,t+1+n);
		for(int i=0;i<=2*n;i++)for(int j=0;j<=n;j++)dp[i][j]=inf;
		dp[0][0]=0;
		for(int i=0;i<2*n;i++){
			for(int j=0;j<=i;j++){
				upd(dp[i+1][j],dp[i][j]);
				upd(dp[i+1][j+1],dp[i][j] + abs(i+1 - t[j+1]));
			}
		}
		int ans=inf;
		for(int i=0;i<=2*n;i++)upd(ans,dp[i][n]);
		printf("%d\n", ans);
	}
}