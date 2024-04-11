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
const int N=3*1e5+100;
int T,n,a[2][N],sum[2][N],last[N][3];
unordered_map <int,int> dp[N];
inline void ckmin(int &a,int b){a=((a<b)?a:b);}
inline void ckmax(int &a,int b){a=((a>b)?a:b);}
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
int DP(int i,int j)
{
	if (i<0||j<0) return -inf;
	if (dp[i].count(j)) return dp[i][j];
	int ans=0,MIN=min(i,j);
	if (i!=j) ans=max(ans,DP(MIN,MIN));
	if (i==MIN) ans=max(ans,DP(i,last[j][1]-1)+1);
	if (j==MIN) ans=max(ans,DP(last[i][0]-1,j)+1);
	ans=max(ans,DP(last[MIN][2]-1,last[MIN][2]-1)+1);
	return dp[i][j]=ans;
}
signed main()
{
	// T=read();
	// while (T--)
	// {
		n=read();
		for (int i=0;i<2;i++) for (int j=1;j<=n;j++) a[i][j]=read(),sum[i][j]=sum[i][j-1]+a[i][j];
		unordered_map <int,int> mp1,mp2,mp3;
		mp1[0]=mp2[0]=mp3[0]=0;
		memset(last,-1,sizeof(last));
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<3;j++) last[i][j]=last[i-1][j];
			if (mp1.count(sum[0][i])) last[i][0]=max(last[i][0],mp1[sum[0][i]]+1);
			if (mp2.count(sum[1][i])) last[i][1]=max(last[i][1],mp2[sum[1][i]]+1);
			int s=sum[0][i]+sum[1][i];
			if (mp3.count(s)) last[i][2]=max(last[i][2],mp3[s]+1);
			mp1[sum[0][i]]=i;mp2[sum[1][i]]=i;mp3[s]=i;
		}
		for (int i=0;i<=n;i++) dp[i].clear();
		printf("%lld\n",DP(n,n));
	// }
}