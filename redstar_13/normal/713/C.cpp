#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef long long INT;
#define NN 3010
int a[NN];
INT dp[NN][NN];
INT ans[NN][NN];
int b[NN];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]-=i;
		b[i]=a[i];
	}
  	sort(b+1,b+n+1);
  	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=abs(b[j]-a[i])+ans[i-1][j];
			if(j>1) ans[i][j]=min(ans[i][j-1],dp[i][j]);
			else ans[i][j]=dp[i][j];
		}
	}
	printf("%I64d\n",ans[n][n]);
    return 0;
}