#include<bits/stdc++.h>
using namespace std;
#define int long long
const int SHIFT=55;
vector<int> G[111];
int ma[111],vis[111];
vector<int> vec,ans;
int dp[111][111],pre[111][111];
bool dfs(int u)
{
	vis[u]=1;
	for(auto v:G[u])
	{
		if(!ma[v])
		{
			vis[v]=1;
			ma[u]=v;
			ma[v]=u;
			return true;
		}
		else if(!vis[v])
		{
			vis[v]=1;
			if(dfs(ma[v]))
			{
				ma[u]=v;
				ma[v]=u;
				return true;
			}
		}
	}
	return false;
}
int n,m,K,u,v;
int x[111],y[111];
signed main()
{
	cin>>n>>m>>K;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		G[u].push_back(v+SHIFT);
		G[v+SHIFT].push_back(u);
	}
	for(int i=1;i<=K;i++)
		cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++)
	{
		if(!ma[i])
		{
			memset(vis,0,sizeof(vis));
			dfs(i);
		}
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		if(!ma[i])
		{
			dfs(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])vec.push_back(i);
		if(vis[i+SHIFT])vec.push_back(-i);
	}
//	for(auto x:vec)cerr<<x<<' ';
	//initial need n-vec.size()
	//dp[i][j],time=i,n-vec.size()+j >i
	memset(dp,-0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=K;i++)
	{
		//j>i+vec.size()-n
		for(int j=max(0ll,i+(int)vec.size()-n+1);j<=(int)vec.size();j++)
		{
			for(int k=0;k<=j;k++)
			{
				if(dp[i-1][j-k]+max(x[i]-k*y[i],0ll)>dp[i][j])
				{
					dp[i][j]=dp[i-1][j-k]+max(x[i]-1ll*k*y[i],0ll);
					pre[i][j]=k;
				}
			}
		}
	}
//	for(int i=0;i<=K;i++)
//		for(int j=0;j<vec.size();j++)
//			cerr<<i<<' '<<j<<' '<<dp[i][j]<<endl;
	int cur=0,val=-0x3f3f3f3f;
	for(int i=0;i<=(int)vec.size();i++)
	{
		if(dp[K][i]>val)
		{
			val=dp[K][i];
			cur=i;
		}
	}
//	cerr<<"final "<<val<<' '<<cur<<endl;
	int ii=0;
	for(int i=K;i>=1;i--)
	{
		ans.push_back(0);
		for(int j=1;j<=pre[i][cur];j++)
		{
			ans.push_back(vec[ii++]);
		}
		cur-=pre[i][cur];
	}
	reverse(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for(auto x:ans)
	{
		cout<<x<<' ';
	}
	cout<<endl;
	return 0;
}