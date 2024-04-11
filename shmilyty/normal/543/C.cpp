#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0,flag=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			flag=0;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
    return (flag?x:~(x-1));
}
const int N = 30;
int n,m,a[N][N];
char s[N][N];
int se[N][N],v[N][N];
int dp[1<<20];
signed main()
{
	n=read();
	m=read();
	for(int i=0;i<n;i++) 
		scanf("%s",s[i]);
	for(int i=0;i<n;i++) 
		for(int j=0;j<m;j++) 
			a[i][j]=read();
	for(int i=0;i<n;i++) 
		for(int j=0;j<m;j++)
		{
			int res=0,maxx=-1;
			for(int k=0;k<n;k++) 
				if(s[k][j]==s[i][j])
				{
					se[i][j]|=(1<<k);
					res+=a[k][j];
					maxx=max(maxx,a[k][j]);
				}
			v[i][j]=res-maxx;
		}
	memset(dp,63,sizeof(dp));
	int S=(1<<n)-1;
	dp[0]=0;
	for(int i=0;i<S;i++)
	{
		int k=0;
		while(i&(1<<k)) 
			k++;
		for(int j=0;j<m;j++)
		{
			dp[i|(1<<k)]=min(dp[i|(1<<k)],dp[i]+a[k][j]);
			dp[i|se[k][j]]=min(dp[i|se[k][j]],dp[i]+v[k][j]);
		}
	}
	cout<<dp[S];
	return 0;
}