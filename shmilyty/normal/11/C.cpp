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
int t,n,m,ans,ok,tx,ty,a[252][252],sq[252][252];
int tx1[]={0,-1,-1,-1,0,0,1,1,1};
int ty1[]={0,-1,0,1,-1,1,-1,0,1};
bool in(int x,int y)
{
	return (x>0&&x<=n&&y>0&&y<=m);
}
void cover(int x,int y)
{
	a[x][y]=0;
	for(int i=1;i<=8;i++)
		if(in(x+tx1[i],y+ty1[i]))
			if(a[x+tx1[i]][y+ty1[i]])
				cover(x+tx1[i],y+ty1[i]);
}
void case1(int x,int y,int tx,int ty)
{
	int side=0;
	if(in(x+(side+1)*tx,y+(side+1)*ty))
		if(a[x+(side+1)*tx][y+(side+1)*ty])
			while(x+(side+1)*tx<=n&&y+(side+1)*ty<=m&&a[x+(side+1)*tx][y+(side+1)*ty])
				side++;
	if(side==0)
		return ;
	memset(sq,0,sizeof(sq));
	int xx=x,yy=y;
	for(int i=1;i<=4;i++)
	{
		for(int l=1;l<=side;l++)
		{
			xx+=tx;
			yy+=ty;
			if(!in(xx,yy))
				return ;
			if(!a[xx][yy])
				return ;
			sq[xx][yy]=1;
		}
		swap(tx,ty);
		ty=-ty;
	}
	xx=x,yy=y;
	for(int i=1;i<=4;i++)
	{
		for(int l=1;l<=side;l++)
		{
			xx+=tx;
			yy+=ty;
			for(int j=1;j<=8;j++)
			{
				int ax=xx+tx1[j];
				int ay=yy+ty1[j];
				if(in(ax,ay))
					if(a[ax][ay]>sq[ax][ay])
						return ;
			}
		}
		swap(tx,ty);
		ty=-ty;
	}
	ans++;
	return ;
}
void dfs(int x,int y)
{
	if(a[x][y+1])
		case1(x,y,0,1);
	else
		case1(x,y,1,1);
	cover(x,y);
}
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		m=read();
		tx=(n-1)/__gcd(n-1,m-1);
		ty=(m-1)/__gcd(n-1,m-1);
		ans=0;
		for(int i=1;i<=n;i++)
		{
			string s;
			cin>>s;
			for(int l=1;l<=m;l++)
				a[i][l]=s[l-1]-'0';
		}
		for(int i=1;i<=n;i++)
			for(int l=1;l<m;l++)
				if(a[i][l])
					dfs(i,l);
		cout<<ans<<endl;
	}
	return 0;
}