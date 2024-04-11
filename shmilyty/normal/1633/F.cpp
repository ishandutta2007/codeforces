#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
//#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
//const int INF=4e18;
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
int n,cnt,num=1,tot=1,x,y,son[200001],sz[200001],fa[200001],id[200001],ok[200001],con[200001],top[200001];
vector<array<int,2>> G[200001];
long long ans;
void dfs(int x,int f)
{
	sz[x]=1;
	fa[x]=f;
	for(auto i:G[x])
		if(i[0]!=f)
		{
			dfs(i[0],x);
//			sz[x]+=sz[i[0]];
			if(sz[son[x]]<sz[i[0]])
				son[x]=i[0];
		}
}
void dfs1(int x,int tp)
{
	top[x]=tp;
	id[x]=++cnt;
	if(son[x])
		dfs1(son[x],tp);
	for(auto i:G[x])
		if(i[0]!=son[x])
		{
			if(i[0]==fa[x])
				con[id[x]]=i[1];
			else
				dfs1(i[0],i[0]);
		}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<n;i++)
	{
//		int x=read(),y=read();
		cin>>x>>y;
		G[x].push_back({y,i});
		G[y].push_back({x,i});	
	}
	dfs(1,0);
	dfs1(1,1);
	int opt;
	cin>>opt;
	ok[1]=1;
	while(opt!=3)
	{
		if(opt==1)
		{
			cin>>x;
			tot++;
			while(x)
			{
				int l=id[top[x]],r=id[x];
				for(int i=l;i<=r;i++)
				{
					num+=(1-2*ok[i]);
					ans+=(1-2*ok[i])*con[i];
					ok[i]^=1;
				}
				x=fa[top[x]];	
			}
			cout<<ans*((num+num)==tot)<<endl;
		}
		elif(num*2!=tot)
			cout<<0<<endl;
		else 
		{	
			set<int> s;
			for(int i=2;i<=n;i++)
				if(ok[i])
					s.insert(con[i]);
			cout<<num<<" ";
			for(int i:s)
			cout<<i<<" ";
			cout<<endl;
		}
		cin>>opt;
		if(opt==0)
		{
			puts("114514");
			return 0;
		}
	}
	return 0;
}