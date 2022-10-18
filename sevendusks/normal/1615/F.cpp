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
const int N=2100;
int T,n,dp[N][N*2],f[N][N*2],lim;
char s[N],t[N];
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
inline void ckmin(int &a,int b){a=((a<b)?a:b);}
inline void ckmax(int &a,int b){a=((a>b)?a:b);}
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
		n=read();
		scanf("%s%s",s+1,t+1);
		for (int i=2;i<=n;i+=2)
		{
			if (s[i]!='?') s[i]=((s[i]-'0')^1)+'0';
			if (t[i]!='?') t[i]=((t[i]-'0')^1)+'0';
		}
		int lim=n;
		for (int i=0;i<=n;i++) for (int j=0;j<=2*n;j++) dp[i][j]=f[i][j]=0;
		dp[0][lim]=0;f[0][lim]=1;
		for (int i=0;i<n;i++)
		{
			for (int j=lim-i;j<=lim+i;j++) if (f[i][j])
			{
				for (int k=0;k<2;k++) for (int p=0;p<2;p++)
				{
					if (s[i+1]=='0'+(k^1)||t[i+1]=='0'+(p^1)) continue;
					int d=j+k-p;
					add(dp[i+1][d],(dp[i][j]+abs(j-lim)*f[i][j])%mod);
					add(f[i+1][d],f[i][j]);
				}
			}
		}
		printf("%lld\n",dp[n][lim]);
	}
}