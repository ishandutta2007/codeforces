#include<bits/stdc++.h>
#define bt bitset<N>
#define pb push_back
using namespace std;
const int N=152,inf=1e9+1e4;
int n,m,ans=inf;
struct Comb{int a,b,t;}h[N];
bool cmp(const Comb &a,const Comb &b){return a.t<b.t;}
int dis[N];
vector<int> e[N];
queue<int> que;
struct Mat
{
	bt v[N];
	void init()
	{
		int i;
		for(i=1;i<=n;i++) v[i].reset();
	}
}f;
Mat operator *(Mat a,Mat b)
{
	Mat c;
	int i,j;
	c.init();
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(a.v[i][j]) c.v[i]|=b.v[j];
		}
	}
	return c;
}
Mat power(Mat x,int cs)
{
	Mat ras;
	int i;
	ras.init();
	for(i=1;i<=n;i++) ras.v[i][i]=1;
	while(cs)
	{
		if(cs&1) ras=ras*x;
		x=x*x;cs>>=1;
	}
	return ras;
}
int main()
{
	ios::sync_with_stdio(false);
	int i,j,x;
	Mat g;
	cin>>n>>m;
	for(i=1;i<=m;i++) cin>>h[i].a>>h[i].b>>h[i].t;
	sort(h+1,h+m+1,cmp);
	if(h[1].t>0)
	{
		puts("Impossible");return 0;
	}
	f.init();f.v[1][1]=1;
	for(i=1;i<=m;i++)
	{
		//printf("solve%d\n",i);
		e[h[i].b].pb(h[i].a);
		memset(dis,0x3f,sizeof(dis));
		dis[n]=0;
		que.push(n);
		while(!que.empty())
		{
			x=que.front();que.pop();
			if(f.v[1][x]) ans=min(ans,dis[x]+h[i].t);
			for(int v:e[x])
			{
				if(dis[x]+1<dis[v])
				{
					dis[v]=dis[x]+1;que.push(v);
				}
			}
		}
		if(i==m) break;
		g.init();
		for(j=1;j<=i;j++) g.v[h[j].a][h[j].b]=1;
		f=f*power(g,h[i+1].t-h[i].t);
		//printf("S%d\n",(int)f.v[1][2]);
	}
	if(ans==inf) puts("Impossible");
	else printf("%d",ans);
	return 0;
}