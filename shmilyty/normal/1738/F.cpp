#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
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
int T,n,rest,d[1001],fa[1001],vis[1001],id[1001];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int ask(int x)
{
	cout<<"? "<<x<<endl;
	return read();
}
bool cmp(int x,int y)
{
	return d[x]>d[y];
}
void solve()
{
	n=rest=read();
	for(int i=1;i<=n;i++)
		d[i]=read();
	for(int i=1;i<=n;i++)
		fa[i]=id[i]=i;
	sort(id+1,id+1+n,cmp);
	fill(vis+1,vis+1+n,0);
	for(int i=1;i<=n&&rest;i++)
		if(!vis[id[i]])
		{
			vis[id[i]]=1;
			while(d[id[i]]--)
			{
				int x=ask(id[i]);
				fa[find(x)]=find(id[i]);
				rest--;
				if(vis[x])
					break;
				vis[x]=1;
				if(!rest)
					break;
			}
		}
	cout<<"! ";
	for(int i=1;i<=n;i++)
		cout<<find(i)<<" ";
	cout<<endl;
}
signed main()
{
	T=read();
	while(T--)
		solve();
	return 0;
}