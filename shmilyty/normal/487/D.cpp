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
const int N=316;
int n,m,q,sq,a[100001][11],vis[100001][11];
array<int,2> f[100001][11];
int tx[]={-1,0,0};
int ty[]={0,1,-1};
bool ok(int x,int y)
{
	return x>sq&&y>0&&y<=m;
}
array<int,2> dfs(int x,int y)
{
	if(!ok(x,y))
		return {-2,-2};
	if(vis[x][y])
		return {-1,-1};
	if(f[x][y][0]!=-10)
		return f[x][y];
	vis[x][y]=1;
	int k=a[x][y];
	f[x][y]=dfs(x+tx[k],y+ty[k]);
	if(f[x][y][0]==-2)
		f[x][y]={x,y};
	vis[x][y]=0;
	return f[x][y];
}
signed main()
{
	n=read();
	m=read();
	q=read();
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		for(int l=0;l<m;l++)
			if(s[l]=='<')
				a[i][l+1]=2;
			elif(s[l]=='>')
				a[i][l+1]=1;
	}
	for(int i=1;i<=n;i++)
		for(int l=1;l<=m;l++)
			f[i][l]={-10,-10};
	for(int i=1;i<=n;i++)
	{
		if(i%N==1)
			sq=i-1;
		for(int l=1;l<=m;l++)
			dfs(i,l);
	}
	while(q--)
	{
		char opt,z;
		cin>>opt;
		int x=read(),y=read();
		if(opt=='C')
		{
			cin>>z;
			if(z=='<')
				a[x][y]=2;
			elif(z=='>')
				a[x][y]=1;
			else
				a[x][y]=0;
			sq=(x-1)/N*N;
			for(int i=x;i<=n&&i<=sq+N;i++)
				for(int l=1;l<=m;l++)
					f[i][l]={-10,-10};
			for(int i=x;i<=n&&i<=sq+N;i++)
				for(int l=1;l<=m;l++)
					dfs(i,l);
		}
		else
		{
			array<int,2> ans={x,y},nxt;
			while(1)
			{
				ans=f[ans[0]][ans[1]];
				if(ans[0]==-1)
					break;
				int k=a[ans[0]][ans[1]];
				nxt={ans[0]+tx[k],ans[1]+ty[k]};
				ans=nxt;
				if(nxt[0]>0&&nxt[1]>0&&nxt[1]<=m)
					continue;
				break;
			}
			cout<<ans[0]<<" "<<ans[1]<<endl;
		}
	}
	return 0;
}