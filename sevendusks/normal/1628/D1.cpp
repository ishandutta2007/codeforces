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
const int N=2100,iv2=(mod+1)/2;
int T,n,m,k,dp[N][N];
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
int DP(int n,int m)
{
	if (n==m) return k*n%mod;
	if (m==0||n==0) return 0;
	if (dp[n][m]!=-1) return dp[n][m];
	return dp[n][m]=(DP(n-1,m)+DP(n-1,m-1))*iv2%mod;
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();m=read();k=read();
		for (int i=0;i<=n;i++) for (int j=0;j<=m;j++) dp[i][j]=-1;
		printf("%lld\n",DP(n,m)); 
	}
}