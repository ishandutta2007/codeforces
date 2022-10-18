/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define int long long
#define len(a) (int)a.size()
using namespace std;
const int N=2100;
int n,mod,dp[N][N],sum[N],f[N],d[N],g[N],fac[N],inv[N];
int pre[N][N],suc[N][N];
vector <int> e[N];
inline void add(int &a,int b){a=((a+b>=mod)?a+b-mod:a+b);}
inline void del(int &a,int b){a=((a-b<0)?a-b+mod:a-b);}
inline void mul(int &a,int b){a=a*b%mod;}
inline int C(int n,int m){return fac[n]*inv[m]%mod*inv[n-m]%mod;}
inline int m_pow(int a,int b)
{
	int ans=1;
	while (b)
	{
		if (b&1) mul(ans,a);
		b>>=1;
		mul(a,a);
	}
	return ans;
}
inline void ckmin(int &a,int b){a=((a<b)?a:b);}
inline void ckmax(int &a,int b){a=((a>b)?a:b);}
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
void prework()
{
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[n]=m_pow(fac[n],mod-2);
	for (int i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
void dfs(int x,int fa)
{
	if (x!=1) e[x].erase(find(e[x].begin(),e[x].end(),fa));
	if (e[x].empty())
	{
		for (int i=1;i<n;i++) dp[x][i]=1;
		return;
	}
	for (int u:e[x]) dfs(u,x);
	if (x==1)
	{
		dp[x][1]=1;
		for (int u:e[x])
		{
			memset(f,0,sizeof(f));
			for (int i=1;i<n;i++)
			{
				add(dp[u][i],dp[u][i-1]);
				add(dp[x][i],dp[x][i-1]);
			}
			for (int i=1;i<n;i++)
			{
				add(f[i],dp[u][i]*dp[x][i]%mod);
				del(f[i],dp[u][i-1]*dp[x][i-1]%mod);
			}
			memcpy(dp[x],f,sizeof(f));
		}
		return;
	}
	if (len(e[x])==1)
	{
		int u=e[x][0];
		for (int i=1;i<n;i++) add(dp[x][i],dp[u][i]*i%mod);
		for (int i=1;i<n;i++) add(dp[u][i],dp[u][i-1]);
		for (int i=1;i<n;i++) add(dp[x][i],dp[u][i-1]);
		return;
	}
	for (int u:e[x]) for (int i=1;i<n;i++) add(dp[u][i],dp[u][i-1]);
	for (int i=1;i<n;i++)
	{
		sum[i]=1;
		for (int u:e[x]) mul(sum[i],dp[u][i]);
		pre[i][0]=dp[e[x][0]][i];
		for (int j=1;j<len(e[x]);j++) pre[i][j]=pre[i][j-1]*dp[e[x][j]][i]%mod;
		suc[i][len(e[x])]=1;
		for (int j=len(e[x])-1;j>=0;j--) suc[i][j]=suc[i][j+1]*dp[e[x][j]][i]%mod;
	}
	int cnt=-1;
	for (int u:e[x])
	{
		cnt++;
		for (int i=1;i<n;i++)
		{
			f[i]=suc[i][cnt+1];
			if (cnt) mul(f[i],pre[i][cnt-1]);
			add(dp[x][i],(dp[u][i]-dp[u][i-1]+mod)*f[i-1]%mod*i%mod);
		}
		for (int i=n-1;i>=1;i--) del(f[i],f[i-1]);
		for (int i=1;i<n;i++) mul(f[i],i),add(f[i],f[i-1]);
		for (int i=1;i<n;i++) del(dp[x][i],(dp[u][i]-dp[u][i-1]+mod)*f[i-1]%mod);
	}
	for (int i=1;i<n;i++) add(dp[x][i],sum[i]);
}
signed main()
{
	n=read();mod=read();
	prework();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);e[v].push_back(u);
	}
	dfs(1,1);
	for (int i=0;i<n-1;i++) g[i]=dp[1][i+1];
	for (int i=0;i<n-1;i++)
	{
		int ans=0;
		for (int j=0;j<=i;j++)
		{
			if ((i-j)&1) del(ans,g[j]*C(i,j)%mod);
			else add(ans,g[j]*C(i,j)%mod);
		}
		printf("%lld ",ans);
	}
	printf("\n");
}