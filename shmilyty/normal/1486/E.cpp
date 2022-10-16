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
struct node{
	int to,nxt,val;
} e[399999];
struct que{
	int to,last,val;
	bool operator<(const que &x)const
	{
		return val>x.val;
	}
};
int n,m,cnt,h[100001],d[100001][51];
priority_queue<que> q;
void add(int x,int y,int z)
{
	e[++cnt].to=y;
	e[cnt].nxt=h[x];
	e[cnt].val=z;
	h[x]=cnt;
}
void dijkstra()
{
	for(int i=1;i<=n;i++)
		for(int l=0;l<=50;l++)
			d[i][l]=114514114514114514;
	d[1][0]=0;
	que p;
	p={1,0,0};
	q.push(p);
	while(!q.empty())
	{
		int f=q.top().to;
		int x=q.top().last;
		q.pop();
		for(int i=h[f];i;i=e[i].nxt)
		{
			int y=e[i].to;
			if(x==0)
				if(d[y][e[i].val]>d[f][0]+e[i].val*e[i].val)
				{
					d[y][e[i].val]=d[f][0]+e[i].val*e[i].val;
					p={y,e[i].val,d[y][e[i].val]};
					q.push(p);
				}
			if(x)
				if(d[y][0]>d[f][x]+e[i].val*e[i].val+2*e[i].val*x)
				{
					d[y][0]=d[f][x]+e[i].val*e[i].val+2*e[i].val*x;
					p={y,0,d[y][0]};
					q.push(p);
				}
		}
	}
}
signed main()
{
	n=read();
	m=read();
	while(m--)
	{
		int x=read(),y=read(),z=read();
		add(x,y,z);
		add(y,x,z);
	}
	dijkstra();
	for(int i=1;i<=n;i++)
		if(d[i][0]==114514114514114514)
			cout<<"-1 ";
		else
			cout<<d[i][0]<<" ";
	return 0;
}