#include <bits/stdc++.h>
using namespace std;
const int N=5e2+2;
int a[N][N];
int t,n,m,i,j,c;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		for (i=1;i<=n;i++)
		{
			c=getchar();
			while (c!='X'&&c!='.') c=getchar();
			a[i][1]=(c=='X');
			for (j=2;j<=m;j++) a[i][j]=(getchar()=='X');
		}
		for (i=1;i<=n;i++) if (i%3==1) for (j=1;j<=m;j++) a[i][j]=1; else if (i%3==0)
		{
			for (j=1;j<=m;j++) if (a[i][j]) {a[i-1][j]=1;break;}
			if (j<=m) continue;
			for (j=1;j<=m;j++) if (a[i-1][j]) {a[i][j]=1;break;}
			if (j>m) a[i][1]=a[i-1][1]=1;
		}
		if (n%3==0) for (j=1;j<=m;j++) if (a[n][j]) a[n-1][j]=1; 
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=m;j++) putchar(a[i][j]?'X':'.');
			puts("");
		}
	}
}