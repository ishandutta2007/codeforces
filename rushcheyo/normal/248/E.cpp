#include<cstdio>
const int N=100005;
int n,q,a[N],ma[N];
double ans,dp[N][105];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),dp[i][ma[i]=a[i]]=1;
	for(int i=1;i<=n;i++)ans+=dp[i][0];
	scanf("%d",&q);
	while(q--){
		int u,v,k;
		scanf("%d%d%d",&u,&v,&k);
		ans-=dp[u][0];
		for(int i=1;i<=k;i++){
			for(int j=0;j<=ma[u];j++)
				dp[u][j]=dp[u][j]*(a[u]-j)/a[u]+dp[u][j+1]*(j+1)/a[u];
			a[u]--;
		}
		printf("%.12f\n",ans+=dp[u][0]);
		a[v]+=k;
	}
}