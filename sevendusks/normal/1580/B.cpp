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
const int N=110;
int n,m,k,mod,dp[N][N],f[N][N],c[N][N];
vector <int> ok[N];
inline void add(int &a,int b){a=((a+b>=mod)?a+b-mod:a+b);}
inline void del(int &a,int b){a=((a-b<0)?a-b+mod:a-b);}
inline void mul(int &a,int b){a=a*b%mod;}
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
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
signed main()
{
	n=read();m=read();k=read();mod=read();
	c[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		c[i][0]=1;
		for (int j=1;j<=i;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
	if (m==n)
	{
		if (k==1) printf("%lld\n",m_pow(2,n-1));
		else printf("0\n");
		return 0;
	}
	dp[0][0]=1;
	for (int i=n;i>=1;i--)
	{
		memset(f,0,sizeof(f));
		for (int j=0;j<=n;j++)
		{
			ok[j].clear();
			for (int k=0;k<=j;k++) if (dp[j][k]) ok[j].push_back(k);
		}
		for (int j=0;j<=n;j++)
		{
			for (int k:ok[j])
			{
				int now=dp[j][k];
				for (int p=0;p<=n-j;p++)
				{
					for (int q:ok[p])
					{
						add(f[j+p+1][k+q+(i==m)],dp[j][k]*dp[p][q]%mod*c[j+p][j]%mod);
					}
				}
			}
		}
		memcpy(dp,f,sizeof(f));
		dp[0][0]=1;
	}
	printf("%lld\n",dp[n][k]);
}