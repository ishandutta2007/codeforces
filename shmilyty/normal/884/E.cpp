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
int n,m,ans,fa[1<<15];
bool vis[2][1<<14];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
char s[1<<14];
signed main()
{
	n=read();
	m=read();
	for(int i=0;i<n;i++)
	{
		int b=i&1;
		scanf("%s",s);
		for(int l=0;l<m/4;l++)
		{
			int k=(s[l]<='9')?(s[l]-'0'):(s[l]-'A'+10);
			for(int j=0;j<4;j++)
				vis[b][l*4+j]=((k>>(3-j))&1);
		}
		for(int l=0;l<m;l++)
			ans+=vis[b][l];
		for(int l=0;l<m;l++)
			fa[b*m+l]=b*m+l;
		for(int l=1;l<m;l++)
			if(vis[b][l]&&vis[b][l-1])
			{
				fa[find(b*m+l)]=find(b*m+l-1);
				ans--;
			}
		for(int l=0;l<m;l++)
			if(vis[b^1][l]&&vis[b][l]&&find(b*m+l)!=find((b^1)*m+l))
			{
				fa[find((b^1)*m+l)]=find(b*m+l);
				ans--;
			}
	}
	cout<<ans;
	return 0;
}