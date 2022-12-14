//cf
#include <cstdio>
const int N=1005;
int n,m,p[N];
double P[N][N],ans;
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		scanf("%d",p+i);
		for (int j=1;j<i;j++)
			if (p[j]<p[i]) P[j][i]=0,P[i][j]=1;
			else P[j][i]=1,P[i][j]=0;
	}
	for (int x,y;m--;) {
		scanf("%d%d",&x,&y);
		for (int t=1;t<=n;t++) {
			if (t==x||t==y) continue;
			P[t][x]=P[t][y]=0.5*(P[t][x]+P[t][y]);
			P[x][t]=P[y][t]=0.5*(P[x][t]+P[y][t]);
		}
		P[x][y]=P[y][x]=0.5;
	}
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++) ans+=P[i][j];
	printf("%.10f\n",ans);
}