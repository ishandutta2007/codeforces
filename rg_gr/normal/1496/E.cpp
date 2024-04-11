#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <math.h>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
char a[505][505];
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read(),m=read();
		for(int i=0;i<n;i++)scanf("%s",a[i]);
		if(n==1)
		{
			for(int i=0;i<m;i++)putchar('X');
			puts("");
			continue;
		}
		for(int i=1;i<n;i+=3)memset(a[i],'X',sizeof(a[i]));
		for(int i=2;i<n;i+=3)
		{
			if(i+2==n)
			{
				for(int j=0;j<m;j++)
				{
					if(a[i][j]=='X'||a[i+1][j]=='X')a[i][j]=a[i+1][j]='X';
				}
				goto hi;
			}
			for(int j=0;j<m;j++)
			{
				if(a[i][j]=='X')
				{
					a[i+1][j]='X';
					goto hi;
				}
				if(i+1<n&&a[i+1][j]=='X')
				{
					a[i][j]='X';
					goto hi;
				}
			}
			a[i][0]=a[i+1][0]='X';
			hi:;
		}
		for(int i=0;i<n;i++,puts(""))
			for(int j=0;j<m;j++)putchar(a[i][j]);
	}
}