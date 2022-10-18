/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define mod 1000000007
#define int long long
#define len(a) (int)a.size()
using namespace std;
const int N=210;
int n,m,dp[N][N][N],fac[N],inv[N],nxt[N];
char s[N];
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
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
void prework()
{
	n=200;
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[n]=m_pow(fac[n],mod-2);
	for (int i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
signed main()
{
	prework();
	n=read();
	scanf("%s",s+1);
	m=strlen(s+1);
	for (int i=2;i<=n;i++)
	{
		int j=nxt[i-1];
		while (j&&s[j+1]!=s[i]) j=nxt[j];
		if (s[j+1]==s[i]) j++;
		nxt[i]=j;
	}
	dp[0][0][0]=1;
	for (int i=0;i<2*n;i++)
	{
		for (int j=0;j<m;j++)
		{
			int pos[2];
			pos[0]=j;
			while (pos[0]&&s[pos[0]+1]!='(') pos[0]=nxt[pos[0]];
			if (s[pos[0]+1]=='(') pos[0]++;
			pos[1]=j;
			while (pos[1]&&s[pos[1]+1]!=')') pos[1]=nxt[pos[1]];
			if (s[pos[1]+1]==')') pos[1]++;
			for (int k=0;k<=n;k++) if (dp[i][j][k])
			{
				if (s[j+1]=='(')
				{
					add(dp[i+1][j+1][k+1],dp[i][j][k]);
					if (k) add(dp[i+1][pos[1]][k-1],dp[i][j][k]);
				}
				else
				{
					add(dp[i+1][pos[0]][k+1],dp[i][j][k]);
					if (k) add(dp[i+1][j+1][k-1],dp[i][j][k]);
				}
			}
		}
	}
	int ans=(C(2*n,n)-C(2*n,n-1)+mod)%mod;
	for (int i=0;i<m;i++) del(ans,dp[2*n][i][0]);
	printf("%lld\n",ans);
}