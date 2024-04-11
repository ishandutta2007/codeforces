#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
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
const int N=1000000;
int q,cnt,tot,ans[N+1],ori[N+1],lst[N+1],fa[N+1],vis[N+1];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
signed main()
{
	tot=q=read();
	for(int i=1;i<=N;i++)
		fa[i]=i;
	for(int i=1;i<=N;i++)
		lst[i]=ori[i]=i;
	while(q--)
	{
		int opt=read();
		if(opt&1)
		{
			int x=read();
			if(vis[x])
			{
				vis[x]=0;
				lst[x]=++tot;
				ori[tot]=x;
			}
			ans[++cnt]=lst[x];
		}
		else
		{
			int x=read(),y=read();
			if(x==y)
				continue;
			if(vis[x])
			{
				vis[x]=0;
				lst[x]=++tot;
				ori[tot]=x;
			}
			if(vis[y])
			{
				vis[y]=0;
				lst[y]=++tot;
				ori[tot]=y;
			}
			fa[lst[x]]=lst[y];
			vis[x]=1;
		}
	}
	for(int i=1;i<=cnt;i++)
		cout<<ori[find(ans[i])]<<" ";
	return 0;
}