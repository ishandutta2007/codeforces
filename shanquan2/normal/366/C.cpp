#include<cstdio>
#include<cstring>
#define M 100000
using namespace std;

int dp[2][200001],a[100],b[100];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	memset(dp,-1,sizeof(dp));
	dp[1][M]=0;
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<n;i++)scanf("%d",&b[i]);
	for(int i=0;i<n;i++){
		int pre=(i&1)^1,now=i&1;
		int v=b[i]*k-a[i];
		for(int j=0;j<=2*M;j++){
			dp[now][j]=dp[pre][j];
			if(j+v>=0 && j+v<=2*M && dp[pre][j+v]!=-1 && dp[pre][j+v]+a[i]>dp[now][j])
				dp[now][j]=dp[pre][j+v]+a[i];
		}
	}
	if(dp[(n-1)&1][M]==0)printf("-1\n");else printf("%d\n",dp[(n-1)&1][M]);
	return 0;
}