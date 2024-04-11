/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=410;
int T,n,m,sum[N],pre[N][N],f[N];
char s[N][N];
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
		for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
		for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) pre[i][j]=pre[i][j-1]+(s[i][j]=='1');
		int ans=inf;
		for (int i=1;i<=m;i++)
		{
			for (int j=i+3;j<=m;j++)
			{
				for (int k=1;k<=n;k++)
				{
					sum[k]=sum[k-1]+pre[k][j-1]-pre[k][i];
					sum[k]+=(s[k][i]=='0')+(s[k][j]=='0');
					f[k]=pre[k][j-1]-pre[k][i];
					f[k]=j-i-1-f[k];
				}
				int MAX=-inf;
				for (int k=5;k<=n;k++)
				{
					MAX=max(MAX,sum[k-4]-f[k-4]);
					ans=min(ans,sum[k-1]+f[k]-MAX);
				}
			}
		}
		printf("%d\n",ans);
	}
}