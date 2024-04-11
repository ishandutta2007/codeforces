#include <bits/stdc++.h>
using namespace std;
const int N=202,inf=-1e9;
int f[N][N][N],s[N];
int c,n,m,i,j,k=0,ans,cnt;
inline void read(int &x)
{
	c=getchar();
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
	read(n);read(m);c=getchar();
	while ((c<'a')||(c>'z')) c=getchar();
	s[1]=c;
	for (i=2;i<=n;i++) s[i]=getchar();c=getchar();
	while ((c<'a')||(c>'z')) c=getchar();
	i=c;j=getchar();
	if (i==j)
	{
		for (i=1;i<=n;i++) if (s[i]==j) ++k;
		k=min(k+m,n);if (!k) return puts("0"),0;
		return printf("%d",k*(k-1)>>1),0;
	}
	for (k=1;k<=n;k++) if (s[k]==i) s[k]=1; else if (s[k]==j) s[k]=2; else s[k]=0;
	for (i=0;i<=n;i++) for (j=0;j<=n;j++) for (k=0;k<=m;k++) f[i][j][k]=inf;
	f[0][0][0]=0;
	for (i=1;i<=n;i++)
	{
		for (j=0;j<=i;j++) for (k=0;(k<=m)&&(k<=i);k++)
		{
			if (s[i]==1)
			{
				if (j) f[i][j][k]=f[i-1][j-1][k];
				if (k) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+j);
			}
			else if (s[i]==2)
			{
				f[i][j][k]=f[i-1][j][k]+j;
				if (j&&k) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k-1]);
			} else
			{
				f[i][j][k]=f[i-1][j][k];
				if (k)
				{
					if (j) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k-1]);
					f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+j);
				}
			}
		}
	}
	for (j=0;j<=n;j++) for (k=0;k<=m;k++) ans=max(ans,f[n][j][k]);
	printf("%d",ans);
}