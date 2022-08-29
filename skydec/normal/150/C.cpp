#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
#define MAXN 160000
double p[MAXN],x[MAXN];int n,m,c;
struct Info
{
	double ls,rs,ms,ss;
	inline Info operator +(const Info &b)const
	{
		Info ans;
		ans.ms=max(max(b.ms,ms),rs+b.ls);
		ans.ls=max(max(ls,ss+b.ls),ss);
		ans.rs=max(max(b.rs,b.ss+rs),b.ss);
		ans.ss=ss+b.ss;
		if(ans.ls<0)ans.ls=0;
		if(ans.rs<0)ans.rs=0;
		if(ans.ms<0)ans.ms=0;
		return ans;
	}
	inline void mk(int u)
	{
		ls=x[u]/2-c*p[u];
		ms=x[u]/2-c*p[u];
		rs=x[u]/2-c*p[u];
		ss=x[u]/2-c*p[u];
		if(ls<0)ls=0;
		if(rs<0)rs=0;
		if(ms<0)ms=0;
	}
}info[MAXN*4];
void build(int now,int l,int r)
{
	if(l==r)
	{
		info[now].mk(l);
		//printf("%d %.5lf\n",x[l],p[l]);
		return;
	}
	int mid=(l+r)>>1;
	build(now*2,l,mid);
	build(now*2+1,mid+1,r);
	info[now]=info[now*2]+info[now*2+1];
}
Info ask(int now,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)return info[now];
	Info xs;xs.mk(0);
	int mid=(l+r)>>1;
	if(x<=mid)xs=xs+ask(now*2,l,mid,x,y);
	if(y>mid)xs=xs+ask(now*2+1,mid+1,r,x,y);
	return xs;
}
int main()
{
	scanf("%d%d%d",&n,&m,&c);
	for(int i=1;i<=n;i++)scanf("%lf",&x[i]);n--;
	for(int i=1;i<=n;i++){scanf("%lf",&p[i]);p[i]/=100.;}
	for(int i=1;i<=n;i++)x[i]=x[i+1]-x[i];
	build(1,1,n);
	double ans=0;
	while(m--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		r--;
		ans+=ask(1,1,n,l,r).ms;
	}
	printf("%.8lf\n",ans);
	return 0;
}