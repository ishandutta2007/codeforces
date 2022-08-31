#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
#define MAXN 310000
#define UP 300000
struct Info
{
	int sum,pos;
	inline Info operator +(const Info &a)const
	{
		Info c;
		if(sum>a.sum)
		{
			c.sum=sum;
			c.pos=pos;
			return c;
		}
		else return a;
	}
}info[MAXN*4];
int lazy[MAXN*4];
void build(int now,int l,int r)
{
	if(l==r)
	{
		info[now].pos=l;
		return;
	}
	int mid=(l+r)>>1;
	build(now*2,l,mid);
	build(now*2+1,mid+1,r);
	info[now]=info[now*2]+info[now*2+1];
}
inline void down(int x)
{
	lazy[x*2]+=lazy[x];
	lazy[x*2+1]+=lazy[x];
	info[x*2].sum+=lazy[x];
	info[x*2+1].sum+=lazy[x];
	lazy[x]=0;
}
void cover(int now,int l,int r,int x,int y,int v)
{
	if(l!=r)
	down(now);
	if(x<=l&&r<=y)
	{
		lazy[now]+=v;
		info[now].sum+=v;
		//printf("_%d\n",info[now].sum);
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)cover(now*2,l,mid,x,y,v);
	if(y>mid)cover(now*2+1,mid+1,r,x,y,v);
	info[now]=info[now*2]+info[now*2+1];
}
int l[MAXN],r[MAXN],v[MAXN];
int n;
struct line
{
	int x,ly,ry,v;
	inline void mk(int a,int b,int c,int d)
	{
		x=a;ly=b;ry=c;v=d;
	}
}data[MAXN];
inline bool cmp(const line &a,const line &b){return a.x<b.x;}
void OUT(int L,int R)
{
	rep(i,1,n)if(l[i]<=L&&L<=v[i]&&v[i]<=R&&R<=r[i])printf("%d ",i);
}
int main()
{
	scanf("%d",&n);rep(i,1,n){scanf("%d%d%d",&l[i],&v[i],&r[i]);data[i*2-1].mk(l[i],v[i],r[i],1);data[i*2].mk(v[i]+1,v[i],r[i],-1);}
	sort(data+1,data+1+2*n,cmp);build(1,1,UP);
	int L,R;L=0;R=0;int res=0;
	rep(i,1,2*n)
	{
		int j=i;while(j<2*n&&data[j+1].x==data[i].x)j++;
		rep(k,i,j)cover(1,1,UP,data[k].ly,data[k].ry,data[k].v);
		Info p=info[1];
		//printf("%d %d\n",p.sum,p.pos);
		if(p.sum>res)
		{
			L=data[i].x;
			R=p.pos;
			res=p.sum;
		}
		i=j;
	}
	printf("%d\n",res);
	OUT(L,R);
	return 0;
}