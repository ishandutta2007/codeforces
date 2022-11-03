#include<bits/stdc++.h>
#include<bitset>
using namespace std;

const int N=10100,inf=1e9;
int a[N],b[N],t[N],dp[2][N][2],ma,mb,n,l,r,w;
bitset<N> f[2];
int main(){
	scanf("%d%d%d",&n,&l,&r);
	for(int i=1;i<=n;i++){
		scanf("%d",&t[i]);
		w+=t[i];
	}
	r=min(r,w);w++;
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		if(x==0)a[++ma]=t[i];else b[++mb]=t[i];
	}
	int now=0;
	f[0][0]=1;
	for(int i=1;i<=ma;i++){
		f[now^1]=f[now]|(f[now]<<a[i]);
		now^=1;
	}
	sort(b+1,b+mb+1);
	for(int i=0;i<=w;i++){
		if(f[now][i])dp[now][i][0]=0;else dp[now][i][0]=-inf;
		dp[now][i][1]=-inf;
	}
	for(int i=mb;i>=1;i--){
		for(int j=0;j<=w;j++)for(int k=0;k<2;k++)dp[now^1][j][k]=-inf;
		for(int j=0;j<=w;j++)for(int k=0;k<2;k++)if(dp[now][j][k]>=0){
			int w=dp[now][j][k];
			dp[now^1][j][1]=max(dp[now^1][j][1],w);
			dp[now^1][min(j+b[i],r+1)][k]=max(dp[now^1][min(j+b[i],r+1)][k],w+(j>=l&&j<=r));
		}
		now^=1;
	}
	int ans=0;
	for(int i=0;i<=w;i++)for(int k=0;k<2;k++)ans=max(ans,dp[now][i][k]+(k&&(i<=r&&i>=l)));
	printf("%d\n",ans);
	return 0;
}