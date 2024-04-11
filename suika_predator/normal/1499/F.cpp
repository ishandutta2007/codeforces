#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long poww(long long x,int y)
{
	long long ret=1;
	while(y)
	{
		if(y&1)ret*=x,ret%=MOD;
		x*=x,x%=MOD;
		y>>=1;
	}
	return ret;
}
int rec[1111111];
inline long long inv(long long x)
{
	if(x<=1000000)
	{
		int &t=rec[x];
		if(t!=-1)return t;
		else return t=poww(x,MOD-2);
	}
	else return poww(x,MOD-2);
}
int n,k;
vector<int> G[5555];
vector<long long> f[5555];
int siz[5555],vis[5555];
void dfs(int u)
{
	vis[u]=1;siz[u]=1;
	vector<int> son;
	vector<long long> prod;
	for(auto v:G[u])
	{
		if(!vis[v])
		{
			dfs(v);
			son.push_back(v);
			siz[u]+=siz[v];
		}
	}
	prod.resize(k+1,1);
	for(auto v:son)
	{
		prod[0]*=f[v][k];prod[0]%=MOD;
		for(int i=0;i<k;i++)
		{
			prod[i+1]*=(f[v][i]+f[v][k]);prod[i+1]%=MOD;
		}
	}
	if(son.empty())
	{
		f[u].resize(k+1,1);
		return;
	}
	f[u].resize(k+1);
	for(int i=0;i<=k;i++)
	{
		if(i+i<=k)
			f[u][i]=prod[i];
		else
		{
			int rem=k-i;
			for(auto v:son)
			{
				f[u][i]+=prod[rem]*inv(((rem==0?0:f[v][rem-1])+f[v][k])%MOD)%MOD*(f[v][i-1]-(i-2>=0?f[v][i-2]:0)+MOD)%MOD;
			}
			f[u][i]=((f[u][i]+f[u][i-1])%MOD+MOD)%MOD;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	memset(rec,-1,sizeof(rec));
	cin>>n>>k;
	int u,v;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
	/*
	for(int i=1;i<=n;i++)
	{
		cerr<<"node "<<i<<", size= "<<siz[i]<<endl;
		for(int j=0;j<=k;j++)
			cerr<<f[i][j]<<' ';
		cerr<<endl;
	}
	*/
	cout<<f[1][k]<<endl;
	return 0;
}