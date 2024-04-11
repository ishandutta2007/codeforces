#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN],p[MAXN],dp[MAXN],dep[MAXN];
vector<int> G[MAXN];
vector<int> save[MAXN];
vector<int> order;
ll root;
bool used[MAXN];
void dfs(ll x,ll d)
{
	ll res=a[x];
	save[d].push_back(x);
	for(ll i=0;i<G[x].size();i++)
	{
		if(G[x][i]==p[x]) continue;
		dfs(G[x][i],d+1);
		res+=dp[G[x][i]];
	}
	dp[x]=res;
	return;
}
void dfs2(ll x)
{
	a[x]=0;
	for(ll i=0;i<G[x].size();i++)
	{
		if(G[x][i]==p[x]) continue;
		dfs2(G[x][i]);
	}

}
int main()
{
	scanf("%I64d",&n);
	ll sum=0;
	for(ll i=0;i<n;i++)
	{
		ll x;
		scanf("%I64d%I64d",&x,&a[i]);
		sum+=a[i];
		p[i]=x-1;
		if(p[i]==-1) root=i;
		if(x!=0)
		{
			G[x-1].push_back(i);
			G[i].push_back(x-1);
		}
	}
	if(sum%3!=0)
	{
		puts("-1");
		return 0;
	}
	memset(dp,-1,sizeof(dp));
	memset(dep,0,sizeof(dep));
	dfs(root,0);
	for(int i=n-1;i>=0;i--)
		for(int j=0;j<save[i].size();j++)
			order.push_back(save[i][j]);
	ll t1=-1,t2=-1;
	sum/=3;
	if(sum==0)
	{
		for(ll i=0;i<n;i++)
		{
			if(i!=root&&dp[i]==0)
			{
				if(t1==-1) {t1=i; continue;}
				if(t2==-1) {t2=i; break;}
			}
		}
		if(t1==-1||t2==-1) puts("-1");
		else printf("%I64d %I64d\n",t1+1,t2+1);
		return 0;
	}
	for(ll i=0;i<n;i++)
	{
		int x=order[i];
		if(x!=root&&dp[x]==sum)
		{
			t1=x;
			break;
		}
	}
	if(t1==-1)
	{
		puts("-1");
		return 0;
	}
	order.clear();
	for(int i=n-1;i>=0;i--)
		save[i].clear();
	dfs2(t1);
	memset(dp,-1,sizeof(dp));
	dfs(root,0);
	for(ll i=0;i<n;i++)
		if(i!=root&&dp[i]==sum)
		{
			t2=i;
			break;
		}
	if(t2==-1)
	{
		puts("-1");
		return 0;
	}
	printf("%I64d %I64d\n",t1+1,t2+1);
	return 0;
}