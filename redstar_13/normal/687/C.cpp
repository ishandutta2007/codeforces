#include <bits/stdc++.h>

using namespace std;
#define NN 510
int a[NN];
int dp[NN][NN];
int ans[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dp[0][0]=1;
	for(int x=1;x<=n;x++){
		for(int i=k;i>=0;i--){
			for(int j=k-i;j>=0;j--){
				if(dp[i][j]) continue;
				if(i>=a[x]&&dp[i-a[x]][j]) dp[i][j]=1;
				else if(j>=a[x]&&dp[i][j-a[x]]) dp[i][j]=1;
			}
		}
	}
	int m=0;
	for(int i=0;i<=k;i++){
		if(dp[i][k-i]) ans[++m]=i;
	}
	printf("%d\n",m);
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
    return 0;
}