/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define m_k make_pair
#define int long long
#define len(a) (int)a.size()
using namespace std;
const int N=4100;
int n,m,a[N],st[N],h,dp[N][N],sz[N],f[N],son[N][2];
inline void ckmin(int &a,int b){a=((a<b)?a:b);}
inline void ckmax(int &a,int b){a=((a>b)?a:b);}
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
void dfs(int x)
{
	sz[x]=1;
	dp[x][0]=0;
	dp[x][1]=(m-1)*a[x];
	for (int i=0;i<2;i++)
	{
		int u=son[x][i];if (!u) continue;
		dfs(u);
		memset(f,-0x3f,sizeof(f));
		for (int j=0;j<=sz[u];j++) 
		{
			for (int i=0;i<=sz[x];i++)
			{
				ckmax(f[i+j],dp[x][i]+dp[u][j]-i*j*a[x]*2);
			}
		}
		memcpy(dp[x],f,sizeof(f));
		sz[x]+=sz[u];
	}
}
signed main()
{
	n=read();m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++)
	{
		while (h&&a[st[h]]>a[i]) son[i][0]=st[h--];
		if (h) son[st[h]][1]=i;
		st[++h]=i;
	}
	int rt=st[1];
	memset(dp,-0x3f,sizeof(dp));
	dfs(rt);
	printf("%lld\n",dp[rt][m]);
}