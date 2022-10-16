#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	bool flag=1;
	int x=0;
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
struct node{
	int to,nxt,id;
} edge[200001];
int t,n,cnt,last,son[100001],in[100001],a[100000],b[100000],vis[100000],fa[100001],head[100001];
pair<int,int> lin[100001];
vector<pair<int,int> > v,ans;
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void add(int x,int y,int z)
{
	edge[++cnt].to=y;
	edge[cnt].id=z;
	edge[cnt].nxt=head[x];
	head[x]=cnt;
}
void dfs(int x,int f,int id)
{
	son[x]=0;
	for(int i=head[x];i;i=edge[i].nxt)
		if(edge[i].to!=f)
		{
			dfs(edge[i].to,x,edge[i].id);
			son[x]=son[x]+1-vis[edge[i].id];
		}
	if(f&&son[x]>1)
		vis[id]=1;
	if(son[x]>1)
	{
		int cnt=2;
		for(int i=head[x];i;i=edge[i].nxt)
			if(!vis[edge[i].id])
			{
				if(cnt)
					cnt--;
				else
					vis[edge[i].id]=1;
			}		
	}
}
void solve()
{
	n=read();
	ans.clear();
	v.clear();
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		lin[i]={0,0};
		head[i]=0;
		in[i]=0;
	}
	for(int i=1;i<n;i++)
	{
		a[i]=read();
		b[i]=read();
		vis[i]=0;
		add(a[i],b[i],i);
		add(b[i],a[i],i);
	}
	dfs(1,0,0);
	for(int i=1;i<n;i++)
		if(vis[i])
			ans.push_back({a[i],b[i]});
		else
		{
			in[a[i]]++;
			in[b[i]]++;
			fa[find(a[i])]=find(b[i]);
		}
	for(int i=1;i<=n;i++)
	{
		if(in[i]==1)
			if(lin[find(i)].first)
				lin[find(i)].second=i;
			else
				lin[find(i)].first=i;
		if(in[i]==0)
			lin[find(i)]={i,i};
	}
	for(int i=1;i<=n;i++)
		if(lin[i].first)
			v.push_back({lin[i].first,lin[i].second});
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
		cout<<ans[i].first<<" "<<ans[i].second<<" "<<v[i].second<<" "<<v[i+1].first<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}