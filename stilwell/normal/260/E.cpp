#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int N,n,i,j,k,l,r,u,d;
int a[15],p[15],pp[15],q[100005],sum[100005][2];
bool use[15];

struct node
{
	int x,y;
}t[100005];
inline bool cmpx(const node &a,const node &b){return a.x<b.x;}
inline bool cmpy(const int &a,const int &b){return t[a].y<t[b].y;}

void dfs2(int x)
{
	if(x==10)
	{
		u=a[p[1]]+a[p[4]]+a[p[7]];
		d=n-a[p[3]]-a[p[6]]-a[p[9]];
		if(t[q[u]].y==t[q[u+1]].y)return;
		if(t[q[d]].y==t[q[d+1]].y)return;
		if(sum[u][0]!=a[p[1]])return;
		if(sum[u][1]!=a[p[4]])return;
		if(sum[d][0]-sum[u][0]!=a[p[2]])return;
		if(sum[d][1]-sum[u][1]!=a[p[5]])return;
		printf("%lf %lf\n",t[l].x+0.5,t[r].x+0.5);
		printf("%lf %lf\n",t[q[u]].y+0.5,t[q[d]].y+0.5);
		exit(0);
	}
	p[x]=pp[x];   p[x+1]=pp[x+1]; p[x+2]=pp[x+2]; dfs2(x+3);
	p[x]=pp[x];   p[x+1]=pp[x+2]; p[x+2]=pp[x+1]; dfs2(x+3);
	p[x]=pp[x+1]; p[x+1]=pp[x];   p[x+2]=pp[x+2]; dfs2(x+3);
	p[x]=pp[x+1]; p[x+1]=pp[x+2]; p[x+2]=pp[x];   dfs2(x+3);
	p[x]=pp[x+2]; p[x+1]=pp[x+1]; p[x+2]=pp[x];   dfs2(x+3);
	p[x]=pp[x+2]; p[x+1]=pp[x];   p[x+2]=pp[x+1]; dfs2(x+3);
}

void dfs(int x)
{
	if(x==10)
	{
		int i;
		l=a[p[1]]+a[p[2]]+a[p[3]];
		r=n-a[p[7]]-a[p[8]]-a[p[9]];
		if(t[l].x==t[l+1].x)return;
		if(t[r].x==t[r+1].x)return;
		N=n-a[p[1]]-a[p[4]]-a[p[7]];
		for(i=1;i<=N;++i)
		{
			sum[i][0]=sum[i-1][0]+(q[i]<=l);
			sum[i][1]=sum[i-1][1]+(q[i]>l&&q[i]<=r);
		}
		for(i=1;i<=9;++i)pp[i]=p[i];
		dfs2(1);
		for(i=1;i<=9;++i)p[i]=pp[i];
		return;
	}
	int i;
	if(x%3==1)i=1;else i=p[x-1];
	for(;i<=9;++i)
	if(!use[i])
	{
		use[i]=true;
		p[x]=i;
		dfs(x+1);
		use[i]=false;
	}
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d%d",&t[i].x,&t[i].y),q[i]=i;
	for(i=1;i<=9;++i)scanf("%d",&a[i]);
	sort(a+1,a+10);
	sort(t+1,t+n+1,cmpx);
	sort(q+1,q+n+1,cmpy);
	dfs(1);
	printf("-1\n");
}