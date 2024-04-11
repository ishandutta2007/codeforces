#include <bits/stdc++.h>
using namespace std;
const int N=72,M=72;
int a[N][N],f[N][M],b[N][M],g[M];
int n,m,q,i,j,k,l;
inline void read(register int &x)
{
	register int c=getchar();
	while ((c<48)||(c>57)) c=getchar();
	x=c^48;c=getchar();
	while ((c>=48)&&(c<=57))
	{
		x=x*10+(c^48);
		c=getchar();
	}
}
int main()
{
	read(n);read(m);read(q);
	for (i=1;i<=n;i++) for (j=1;j<=m;j++) {read(a[i][j]);b[i][j]=a[i][j]/q;a[i][j]%=q;}
	for (i=1;i<q;i++) g[i]=-1e6;
	g[0]=0;
	for (i=1;i<=n;i++)
	{
		for (j=0;j<q;j++) f[0][j]=g[j];
		for (j=1;j<=m;j++)
		{
			for (l=0;l<q;l++) f[j][l]=-1e6;
			for (l=min(m>>1,j);l;l--)
			{
				for (k=q-1;k>=a[i][j];k--)
				f[l][k]=max(f[l][k],f[l-1][k-a[i][j]]+b[i][j]);
				for (k=a[i][j]-1;k>=0;k--)
				f[l][k]=max(f[l][k],f[l-1][k-a[i][j]+q]+1+b[i][j]);
			}
		//	for (k=0;k<q;k++) printf("%d ",g[k]);puts("");
		}
		for (j=0;j<=m>>1;j++) for (k=0;k<q;k++) g[k]=max(g[k],f[j][k]);
		//for (k=0;k<q;k++) printf("%d ",g[k]);puts("");
	}
	printf("%d",g[0]*q);
}