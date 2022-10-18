#include <bits/stdc++.h>
using namespace std;
const int N=1e3+2;
int a[3][N][N],b[N][N],p[3],mv[3];
int n,m,t,i,j,c;
inline void read(int &x)
{
	int c=getchar();
	while (c<48||c>57) c=getchar();
	x=c^48;c=getchar();
	while (c>=48&&c<=57) x=x*10+(c^48),c=getchar();
}
int main()
{
	read(t);
	while (t--)
	{
		read(n);read(m);
		for (i=1;i<=n;i++) for (j=1;j<=n;j++) a[0][i][j]=i;
		for (i=1;i<=n;i++) for (j=1;j<=n;j++) a[1][i][j]=j;
		for (i=1;i<=n;i++) for (j=1;j<=n;j++) read(a[2][i][j]);
		p[0]=0;p[1]=1;p[2]=2;c=getchar();
		mv[0]=mv[1]=mv[2]=0;
		while (c<'A'||c>'Z') c=getchar();
		while (m--)
		{
			if (c=='U') --mv[p[0]];
			else if (c=='D') ++mv[p[0]];
			else if (c=='L') --mv[p[1]];
			else if (c=='R') ++mv[p[1]];
			else if (c=='I') swap(p[1],p[2]);
			else swap(p[0],p[2]);
			c=getchar();
		}
		mv[0]%=n;if (mv[0]<0) mv[0]+=n;
		mv[1]%=n;if (mv[1]<0) mv[1]+=n;
		mv[2]%=n;if (mv[2]<0) mv[2]+=n;
		for (i=1;i<=n;i++) for (j=1;j<=n;j++) b[(a[p[0]][i][j]+mv[p[0]]-1)%n+1][(a[p[1]][i][j]+mv[p[1]]-1)%n+1]=(a[p[2]][i][j]+mv[p[2]]-1)%n+1;
		for (i=1;i<=n;i++) for (j=1;j<=n;j++) printf("%d%c",b[i][j],j==n?10:32);
	}
}