#include <bits/stdc++.h>
#define bctz(x) (__builtin_ctz(x))
using namespace std;
#define NN 22
char s[NN][NN];
int dp[1<<NN];
int a[NN][NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	}
	memset(dp,0x3f,sizeof dp);
	dp[0]=0;
	for(int i=0;i<1<<n;i++){
		int x=bctz(~i);
		int v=1<<x;
		for(int j=1;j<=m;j++) dp[i|v]=min(dp[i|v],dp[i]+a[x+1][j]);
		for(int j=1;j<=m;j++){
			int val=0,mx=0,y=i;
			for(int k=1;k<=n;k++){
				if(s[k][j]!=s[x+1][j]) continue;
				y|=1<<(k-1);
				mx=max(mx,a[k][j]);
				val+=a[k][j];
			}
			dp[y]=min(dp[y],dp[i]+val-mx);
		}
	}
	printf("%d\n",dp[(1<<n)-1]);
    return 0;
}