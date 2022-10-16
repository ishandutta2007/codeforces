#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAXN=133333,SHIFT=100001,MOD=1e9+7;
int n,m;
struct point
{
	int x,y,ix,iy;
}p[MAXN];
int pow2[MAXN*2];
inline bool cmpx(const point &a,const point &b)
{
	return a.x<b.x;
}
inline bool cmpy(const point &a,const point &b)
{
	return a.y<b.y;
}
struct edge
{
	int v;
	edge *next;
}pool[MAXN*2],*h[MAXN*2];
int top;
int vis[MAXN*2];
inline void addedge(int u,int v)
{
	edge *tmp=&pool[top++];tmp->v=v;tmp->next=h[u];h[u]=tmp;
	edge *pmt=&pool[top++];pmt->v=u;pmt->next=h[v];h[v]=pmt;
	vis[u]=vis[v]=0;
}
typedef pair<int,bool> pib;
pib dfs(int u,int pa)
{
	bool tree=1;
	int cnt=1;
	pib tt;
	vis[u]=1;
	for(edge *tmp=h[u];tmp;tmp=tmp->next)
	{
		if(tmp->v==pa)continue;
		if(vis[tmp->v])tree=0;
		else
		{
			tt=dfs(tmp->v,u);
			cnt+=tt.first;
			tree&=tt.second;
		}
	}
	return make_pair(cnt,tree);
}
int main()
{
	int ans=1;
	scanf("%d",&n);
	p[0].x=p[0].y=0x3f3f3f3f;
	pow2[0]=1;
	for(int i=1;i<MAXN*2;i++)
	{
		pow2[i]=(pow2[i-1]*2)%MOD;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
	}
	sort(p+1,p+n+1,cmpx);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(p[i].x!=p[i-1].x)cnt++;
		p[i].ix=cnt;
	}
	sort(p+1,p+n+1,cmpy);
	for(int i=1;i<=n;i++)
	{
		if(p[i].y!=p[i-1].y)cnt++;
		p[i].iy=cnt;
	}
	for(int i=1;i<=n+SHIFT;i++)vis[i]=1;
	for(int i=1;i<=n;i++)addedge(p[i].ix,p[i].iy+SHIFT);
	for(int i=1;i<=n+SHIFT;i++)
	{
		if(!vis[i])
		{
			pib res=dfs(i,-1);
			//cout<<i<<' '<<res.first<<' '<<res.second<<endl;
			ans=(((long long)ans*(pow2[res.first]-res.second))%MOD+MOD)%MOD;
		}
	}
	printf("%d\n",ans);
	return 0;
}