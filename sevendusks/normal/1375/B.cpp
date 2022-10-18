/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=310;
int T,n,m,a[N][N];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();m=read();
		for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) a[i][j]=read();
		bool bl=1;
		for (int i=1;i<=n;i++) for (int j=1;j<=m;j++)
		{
			int cnt=0;
			for (int k=0;k<4;k++)
			{
				int tx=i+dx[k],ty=j+dy[k];
				if (tx<=0||ty<=0||tx>n||ty>m) continue;
				cnt++;
			}
			if (cnt<a[i][j]) bl=0;
		}
		if (!bl)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				int cnt=0;
				for (int k=0;k<4;k++)
				{
					int tx=i+dx[k],ty=j+dy[k];
					if (tx<=0||ty<=0||tx>n||ty>m) continue;
					cnt++;
				}
				printf("%d ",cnt);
			}
			printf("\n");
		}
	}
}