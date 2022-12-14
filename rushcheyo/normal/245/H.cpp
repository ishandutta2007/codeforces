#include <cstdio>
const int N=5005;
int n,q,dp[N][N];
char s[N];
int main() {
	scanf("%s",s+1);
	for (n=1;s[n];n++); n--;
	for (int i=1;i<=n;i++) {
		dp[i][i]=1;
		if (i>1) dp[i-1][i]=s[i]==s[i-1];
	}
	for (int i=n-2;i>=1;i--)
		for (int j=i+2;j<=n;j++)
			if (s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
	for (int i=n-1;i>=1;i--)
		for (int j=i+1;j<=n;j++)
			dp[i][j]+=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
	scanf("%d",&q);
	for (int i,j;q--;) {
		scanf("%d%d",&i,&j);
		printf("%d\n",dp[i][j]);
	}
}