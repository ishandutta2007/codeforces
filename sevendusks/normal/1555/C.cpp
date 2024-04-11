/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=1e5+100;
int t,n,a[2][N],sum[2][N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
signed main()
{
	t=read();
	while (t--)
	{
		n=read();
		for (int i=0;i<2;i++)
		{
			for (int j=1;j<=n;j++)
			{
				a[i][j]=read();
				sum[i][j]=sum[i][j-1]+a[i][j];
			}
		}
		int ans=inf;
		for (int i=1;i<=n;i++) ans=min(ans,max(sum[1][i-1],sum[0][n]-sum[0][i]));
		printf("%d\n",ans);
	}
}