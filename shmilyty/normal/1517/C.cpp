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
int n,a[501],now,ans[501][501];
int tx[]={-1,0,1,0};
int ty[]={0,-1,0,1};
bool ok(int x,int y)
{
	return (x>=1&&x<=n&&y>=1&&y<=x);
}
void dfs(int x,int y,int g)
{
	ans[x][y]=g;
	now--;
	if(!now)
		return ;
	for(int i=0;i<4;i++)
		if(ok(x+tx[i],y+ty[i]))
		if(!ans[x+tx[i]][y+ty[i]])
		{
			dfs(x+tx[i],y+ty[i],g);
			if(!now)
				return ;
		}
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		now=read();
		dfs(i,i,now);
	}
	for(int i=1;i<=n;i++)
	{
		for(int l=1;l<=i;l++)
			cout<<ans[i][l]<<" ";
		cout<<endl;
	}
	return 0;
}