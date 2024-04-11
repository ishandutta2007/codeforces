#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define y1 zmakioi
const int N=210;
int n;
int a[210][210];
int s[210][210];
int pre[210][210];
int dp[210][210];
int g[210][210];
int f[210];
inline int cal(int l,int r)
{
	if(l>r) return 0;
	return s[r][n]-s[l-1][n]-s[r][r]+s[l-1][r]+s[r][l-1]-s[l-1][l-1];
}
inline void solve(int l,int r)
{
	if(r<=l) return;	
	int rt=g[l][r];
	if(l<=rt-1)
	{
		f[g[l][rt-1]]=rt;
		solve(l,rt-1);
	}
	if(rt+1<=r)
	{
		f[g[rt+1][r]]=rt;
		solve(rt+1,r);
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	//memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			cin>>a[i][j];
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
		}
	}
	for(int i=1;i<=n;++i) dp[i][i]=cal(i,i),g[i][i]=i;
	for(int len=2;len<=n;++len)
	{
		for(int l=1,r=l+len-1;r<=n;++l,++r)
		{
			dp[l][r]=4e18;
			for(int k=l;k<=r;++k)
			{
				//dp[l][r]=min(dp[l][r],dp[l][k-1]+dp[k+1][r]+(pre[k][r]-pre[k][l-1]-a[k][k])+cal(l,r));
				//dp[l][r]=min(dp[l][r],dp[l][k-1]+dp[k+1][r]+cal(l,k-1)+cal(k+1,r)-(s[r][k-1]-s[r][l-1]-s[k][k-1]+s[k][l-1]));
				int tmp=dp[l][k-1]+dp[k+1][r]+cal(l,r);
				if(tmp<dp[l][r]) dp[l][r]=tmp,g[l][r]=k;
				//cout<<l<<' '<<r<<' '<<g[l][r]<<"!!"<<endl;
			}
		}
	}
	solve(1,n);

	for(int i=1;i<=n;++i) cout<<f[i]<<" \n"[i==n];
	return 0;
}
/*
0 0
2 3
3 2

*/