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
struct node{
	int to,nxt;
} edge[400001];
int t,n,cnt,dep,ans,a[200001],head[200001],dis[200001],f[200001];
vector<array<int,3> > d[200001];
void add(int x,int y)
{
	edge[++cnt].to=y;
	edge[cnt].nxt=head[x];
	head[x]=cnt;
}
void dfs(int x,int fa)
{
	for(int i=head[x];i;i=edge[i].nxt)
		if(edge[i].to!=fa)
		{
			dis[edge[i].to]=dis[x]+1;
			dep=max(dep,dis[x]+1);
			d[dis[x]+1].push_back({a[edge[i].to],x,edge[i].to});
			dfs(edge[i].to,x);
		}
}
signed main()
{
	t=read();
	while(t--)
	{
	    dep=0;
		n=read();
		dis[1]=0;
		for(int i=1;i<=n;i++)
		    f[i]=0;
		for(int i=1;i<=n;i++)
		    d[i].clear();
		for(int i=1;i<=n;i++)
		    head[i]=0;
		for(int i=2;i<=n;i++)
		{
			int x=read();
			add(i,x);
			add(x,i);
		}
		for(int i=2;i<=n;i++)
			a[i]=read();
		dfs(1,0);
		for(int i=1;i<=dep;i++)
		{
			sort(d[i].begin(),d[i].end());
			int s=d[i].size();
			int s1=d[i][0][0],s2=d[i][s-1][0];
			for(int l=0;l<s;l++)
				f[d[i][l][2]]=max(f[d[i][l][2]],f[d[i][l][1]]+max(d[i][l][0]-s1,s2-d[i][l][0]));
			int x=0;
			for(int l=0;l<s;l++)
			{
				if(f[d[i][l][1]]-d[i][l][0]>f[d[i][x][1]]-d[i][x][0])
					x=l;
				f[d[i][l][2]]=max(f[d[i][l][2]],f[d[i][x][1]]-d[i][x][0]+d[i][l][0]);
			}
			x=s-1;
			for(int l=s-1;l>=0;l--)
			{
				if(f[d[i][l][1]]+d[i][l][0]>f[d[i][x][1]]+d[i][x][0])
					x=l;
				f[d[i][l][2]]=max(f[d[i][l][2]],f[d[i][x][1]]+d[i][x][0]-d[i][l][0]);
			}
		}
		ans=0;
		for(int i=1;i<=n;i++)
			ans=max(ans,f[i]);
		cout<<ans<<endl;
	}
	return 0;
}