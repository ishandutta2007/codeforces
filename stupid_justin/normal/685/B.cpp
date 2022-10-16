#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,m,cnt;
int fa[N],head[N],ans[N],sz[N],mx[N];
struct Edge
{
	int to,nxt;
}edge[N];
void dfs(int now,int pre)
{
	sz[now]=1;
	for(int i=head[now];i;i=edge[i].nxt)
	{
		dfs(edge[i].to,now);
		sz[now]+=sz[edge[i].to];
		mx[now]=max(mx[now],sz[edge[i].to]);
	}
	int index=now,me=mx[now];
	for(int i=head[now];i;i=edge[i].nxt)
	{
		int it=ans[edge[i].to],pre=std::max(mx[it],sz[now]-sz[it]),p=it;
		while(fa[it]!=now)
		{
			it=fa[it];
			int New=max(mx[it],sz[now]-sz[it]);
			if(New<pre)pre=New,p=it;else break;
		}
		if(me>pre)
		{
			me=pre;
			index=p;
		}
	}
	ans[now]=index;
}
int main()
{
	cin>>n>>m;
	for(int i=2;i<=n;++i)
	{
		cin>>fa[i];
		edge[++cnt]=(Edge){i,head[fa[i]]};head[fa[i]]=cnt;
	}
	dfs(1,0);
	while(m--)
	{
		int x;
		cin>>x;
		cout<<ans[x]<<endl;
	}
	return 0;
}