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
int n,m,x,y,a,b,ans,mp[2001][2001],dis[2001][2001];
deque<pair<int,int> > deq;
int px[]={0,1,0,-1};
int py[]={1,0,-1,0};
bool ok(int x,int y)
{
	return (x&&y&&x<=n&&y<=m); 
}
signed main()
{
//	freopen("e.in","r",stdin);
//	freopen("e.out","w",stdout);
	n=read();
	m=read();
	x=read();
	y=read();
	a=read();
	b=read();
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		for(int l=0;l<m;l++)
			if(s[l]=='*')
				mp[i][l+1]=1;
	}
	for(int i=1;i<=n;i++)
		for(int l=1;l<=m;l++)
			dis[i][l]=114514114514114514;
	dis[x][y]=0;
	deq.push_back({x,y});
	while(!deq.empty())
	{
		pair<int,int> p=deq.front();
		int xx=p.first,yy=p.second;
		deq.pop_front();
		for(int i=0;i<4;i++)
			if(ok(xx+px[i],yy+py[i]))
				if(!mp[xx+px[i]][yy+py[i]])
				{
					if(i)
					{
						if(dis[xx+px[i]][yy+py[i]]>dis[xx][yy])
						{
							dis[xx+px[i]][yy+py[i]]=dis[xx][yy];
							deq.push_front({xx+px[i],yy+py[i]});
						}
					}
					else
						if(dis[xx+px[i]][yy+py[i]]>dis[xx][yy]+1)
						{
							dis[xx+px[i]][yy+py[i]]=dis[xx][yy]+1;
							deq.push_back({xx+px[i],yy+py[i]});
						}
				}
	}
	for(int i=1;i<=n;i++)
		for(int l=1;l<=m;l++)
			if(dis[i][l]!=114514114514114514)
			{
				int right=dis[i][l];
				int left=right+y-l;
				if(left<=a&&right<=b)
					ans++;
			}
	cout<<ans;
	return 0;
}