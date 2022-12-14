#include <cstdio>
const int N=100005;
typedef unsigned ui;
const ui P=1000000007;
int n,m,k,x,tot,nxt[2*N],fst[N],to[2*N];
ui dp[N][11][3];
void dfs(int u,int fa) {
	dp[u][0][0]=k-1,dp[u][1][1]=1,dp[u][0][2]=m-k;
	for (int i=fst[u];i;i=nxt[i])
		if (to[i]!=fa) {
			dfs(to[i],u);
			ui tmp[11][3]={};
			for (int j=x;j>=0;j--)
				for (int k=0;k<=j;k++) {
					tmp[j][0]=(tmp[j][0]+1llu*(dp[to[i]][k][0]+dp[to[i]][k][1]+dp[to[i]][k][2])*dp[u][j-k][0])%P;
					tmp[j][1]=(tmp[j][1]+1llu*dp[to[i]][k][0]*dp[u][j-k][1])%P;
					tmp[j][2]=(tmp[j][2]+1llu*(dp[to[i]][k][0]+dp[to[i]][k][2])*dp[u][j-k][2])%P;
				}
			for (int j=0;j<=x;j++)
				for (int k=0;k<3;k++) dp[u][j][k]=tmp[j][k];
		}
}
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1,u,v;i<n;i++) {
		scanf("%d%d",&u,&v);
		nxt[++tot]=fst[u];fst[u]=tot;to[tot]=v;
		nxt[++tot]=fst[v];fst[v]=tot;to[tot]=u;
	}
	scanf("%d%d",&k,&x);
	dfs(1,0);
	ui ans=0;
	for (int i=0;i<=x;i++) ans=(ans+dp[1][i][0]+dp[1][i][1]+dp[1][i][2])%P;
	printf("%u\n",ans);
}