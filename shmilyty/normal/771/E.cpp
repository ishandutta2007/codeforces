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
map<int,int> lst,f[300001];
int n,a[3][300001],pre[3][300001];
int dfs(int x,int y)
{
	if(x<0||y<0)
		return -INF;
	if(x==0&&y==0)
		return 0;
	if(f[x][y])
		return f[x][y];
	f[x][y]=0;
	if(pre[0][x]>pre[1][y])
		f[x][y]=max(f[x][y],dfs(pre[0][x],y)+1);
	else
		f[x][y]=max(f[x][y],dfs(x,pre[1][y])+1);
	f[x][y]=max(f[x][y],dfs(pre[2][min(x,y)],pre[2][min(x,y)])+1);
	return f[x][y];
}
signed main()
{
	n=read();
	for(int i=0;i<2;i++)
		for(int l=1;l<=n;l++)
		{
			a[i][l]=a[i][l-1]+read();
			a[2][l]+=a[i][l];
		}
	for(int i=0;i<3;i++)
	{
		lst.clear();
		lst[0]=-1;
		pre[i][0]=-1;
		for(int l=1;l<=n;l++)
		{
			pre[i][l]=-1;
			if(lst[a[i][l]])
				pre[i][l]=max(0ll,lst[a[i][l]]);
			pre[i][l]=max(pre[i][l],pre[i][l-1]);
			lst[a[i][l]]=l;
		}
	}
	cout<<dfs(n,n)<<endl;
	return 0;
}