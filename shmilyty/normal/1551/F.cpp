#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int t,n,k,cnt,ans,num[101][101],f[101];
vector<int> G[101]; 
const int mod=1e9+7;
void dfs(int x,int fa,int d)
{
	num[d][cnt]++;
	for(int i:G[x])
		if(i!=fa)
			dfs(i,x,d+1);
}
void solve()
{
	n=read();
	k=read();
	ans=0;
	for(int i=1;i<=n;i++)
		G[i].clear();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	if(k==2)
	{
		cout<<n*(n-1)/2<<endl;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		cnt=0;
		for(int l:G[i])
		{
			cnt++;
			dfs(l,i,1);
		}
		for(int l=1;l<=n;l++)
		{
			for(int j=0;j<=k;j++)
				f[j]=0;
			f[0]=1;
			for(int j=1;j<=cnt;j++)
				for(int q=k;q;q--)
					(f[q]+=f[q-1]*num[l][j]%mod)%=mod;
			(ans+=f[k])%=mod;
			for(int j=1;j<=cnt;j++)
				num[l][j]=0;
		}
	}
	cout<<ans<<endl;
}
signed main()
{
	t=read();
	while(t--)	
		solve();
	return 0;
}