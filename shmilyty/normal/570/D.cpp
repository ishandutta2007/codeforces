#include<bits/stdc++.h>
#define int long long
using namespace std; 
int n,m,son[500001],bro[500001];
struct node{
	int id,d;
};
vector<node> query[500001];
int cnt[500001][30],ans[500001];
char col[500001];
bool check(int x)
{
	int ret=0;
	for(int i=1;i<=26;i++)
		ret+=(cnt[x][i]&1);
	return ret<=1;
}
int in[500001],out[500001],tot,id[500001];
int sz[500001],dep[500001],hev[500001];
void dfs1(int x)
{
	in[x]=++tot;
	id[tot]=x;
	sz[x]=1;
	int heavy=-1926;
	for(int v=son[x];v;v=bro[v])
	{
		dep[v]=dep[x]+1;
		dfs1(v);
		sz[x]+=sz[v];
		if(sz[v]>heavy)
		{
			heavy=sz[v];
			hev[x]=v;
		}
	}
	out[x]=tot;
}
void add(int u)
{
	cnt[dep[u]][col[u]-'a'+1]++;
}
void update(int u)
{
	for(int i=in[u];i<=out[u];i++)
		add(id[i]);
}
void del(int u)
{
	cnt[dep[u]][col[u]-'a'+1]=0;
}
void erase(int u)
{
	for(int i=in[u];i<=out[u];i++)
		del(id[i]);
}
void dfs2(int x,int flag)
{
	for(int v=son[x];v;v=bro[v])
	{
		if(v==hev[x])
			continue;
		dfs2(v,0);
	}
	if(hev[x])
		dfs2(hev[x],1);
	for(int v=son[x];v;v=bro[v])
	{
		if(v==hev[x])
			continue;
		update(v);
	}
	add(x);
	for(int i=0;i<query[x].size();i++)
		ans[query[x][i].id]=check(query[x][i].d);
	if(flag)
		return;
	erase(x);
} 
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=2;i<=n;i++)
	{
		int x;
		scanf("%lld",&x);
		bro[i]=son[x];
		son[x]=i;
	}
	scanf("%s",col+1);
	for(int i=1;i<=m;i++)
	{
		int u,x;
		scanf("%lld%lld",&u,&x);
		query[u].push_back((node){i,x});
	}
	dep[1]=1;
	dfs1(1);
	dfs2(1,0);
	for(int i=1;i<=m;i++)
	{
		if(ans[i])
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}