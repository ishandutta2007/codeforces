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
int n,num,vis[1000],vis1[1000],dep[1000],lf[1000],con[1000][1000],sz[1000];
std::vector<int> v,G[1000];
bitset<1000>a[1000],b[1000];
void dfs(int x,int y)
{
	for(int i:G[x])
		if(i!=y)
		{
			dep[i]=dep[x]+1;
			dfs(i,x);
		}
}
signed main()
{
	n=read();
	if(n==2)
	{
		cout<<"1 2";
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		int x=read();
		sz[i]=x;
		while(x--)
			a[i][read()-1]=1;
	}
	for(int i=0;i<n;i++)
		for(int l=i+1;l<n;l++)
		{
			bitset<1000> x=a[i]&a[l];
			if(x.count()==2)
			{
				int y=x._Find_first(),z=x._Find_next(y);
				if(con[y][z])
					continue;
				con[y][z]=1;
				vis[z]=vis[y]=1;
				cout<<z+1<<" "<<y+1<<endl;
				G[z].push_back(y);
				G[y].push_back(z);
			}
		}
	// cout<<endl;
	for(int i=0;i<n;i++)
	{
		num+=vis[i];
		if(vis[i])
			v.push_back(i);
	}
	if(!num)
	{
		for(int i=2;i<=n;i++)
			cout<<i<<" 1\n";
		return 0;
	}
	memset(lf,-1,sizeof(lf));
	for(int i=0;i<n;i++)
		for(int l=0;l<n;l++)
			if(a[i][l]&&!vis[l])
				if(lf[l]<0||sz[lf[l]]>sz[i])
					lf[l]=i;
	// for(int i=0;i<n;i++)
		// if(!vis[i])
			// cout<<lf[i]<<endl;
	// cout<<endl;
	if(num==2)
	{
		int x;
		for(int i=0;i<n;i++)
			if(!vis[i])
			{
				x=i;
				break;
			}
		// cout<<x<<endl;
		std::vector<int> v1,v2;
		for(int i=0;i<n;i++)
			if(!vis[i])
			{
				if(a[lf[x]][i])
					v1.push_back(i);
				else
					v2.push_back(i);
			}
		for(int i:v1)
			cout<<i+1<<" "<<v[0]+1<<'\n';
		for(int i:v2)
			cout<<i+1<<" "<<v[1]+1<<'\n';
		return 0;
	}
	for(int i=0;i<v.size();i++)
	{
		b[i][v[i]]=1;
		for(int l:G[v[i]])
			b[i][l]=1;
	}
	for(int i=0;i<n;i++)
		if(!vis[i])
		{
			for(int l=0;l<n;l++)
				if(!vis[l])
					a[lf[i]][l]=0;
			for(int l=0;l<v.size();l++)
				if(b[l]==a[lf[i]])
					cout<<v[l]+1<<" "<<i+1<<'\n';
		}
	return 0;
}