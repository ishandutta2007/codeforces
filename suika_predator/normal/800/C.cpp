#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
int n,m;
int x,fl[233333];
vector<int> fact,fafa,ans;
int ext_euc(int a, int b, int &x, int &y)
{
	if(b == 0) // gcd(a, b) == a
	{
		x = 1;
		y = 0;
		return a;
	}
	int w = ext_euc(b, a%b, x, y);
	int tmp = x;
	x = y;
	y = tmp - int(a/b)*y;
	return w;
}
int vis[233333],cnt[233333],deg[233333],dp[233333],last[233333];
queue<int> q;
struct edge
{
	int v;
	edge *next;
}*h[233333],pool[233333];
int top;
inline void addedge(int u,int v)
{
	edge *tmp=&pool[top++];tmp->v=v;tmp->next=h[u];h[u]=tmp;deg[v]++;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&x);
		fl[x]=1;
	}
	int s=sqrt(m);
	for(int i=1; i<=s; i++)
	{
		if(m%i==0)
		{
			fact.push_back(i);
			if(m/i!=i)fact.push_back(m/i);
		}
	}
	sort(fact.begin(),fact.end());
	for(int t=0;t<fact.size();t++)
	{
		for(int tt=0;tt<t;tt++)
			if(fact[t]%fact[tt]==0)
				addedge(fact[t],fact[tt]);
	}
	for(int i=0;i<m;i++)if(!fl[i])cnt[__gcd(i,m)]++;
	
//	for(int i=1;i<=m;i++)cout<<i<<' '<<cnt[i]<<endl;
	memset(dp,-1,sizeof(dp));
	dp[m]=0;
	q.push(m);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		dp[u]+=cnt[u];
		for(edge *tmp=h[u];tmp;tmp=tmp->next)
		{
//			cout<<u<<"->"<<tmp->v<<endl;
			if(dp[tmp->v]<=dp[u])
			{
				last[tmp->v]=u;
				dp[tmp->v]=dp[u];
			}
			deg[tmp->v]--;
			if(deg[tmp->v]==0)q.push(tmp->v);
		}
	}
	int cur=1;
	fafa.push_back(cur);
	while(cur!=m)
	{
//		cout<<cur<<' '<<last[cur]<<' '<<dp[cur]<<endl;
		cur=last[cur];
		fafa.push_back(cur);
	}
	cur=1;
	for(int t=0; t<fafa.size(); t++)
	{
		for(int i=0; i<m; i++)
		{
			if(fl[i]||__gcd(i,m)!=fafa[t])continue;
//			cout<<"proceed "<<i<<endl;
			int tmp,qwq;
			int d=ext_euc(cur,m,tmp,qwq);
			if(tmp<0)tmp+=m;
//			cout<<"ext_euc "<<cur<<' '<<m<<' '<<tmp<<' '<<qwq<<' '<<d<<endl;
			if(i%d==0)
			{
				ans.push_back((1ll*tmp*(i/d))%m);
				cur=i;
			}
		}
	}
	printf("%d\n",ans.size());
	for(int i=0; i<ans.size(); i++)printf("%d ",ans[i]);
	printf("\n");
//	int tmp=1;for(int i=0;i<ans.size();i++)tmp=tmp*ans[i]%m,cout<<tmp<<' ';
	return 0;
}