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
typedef long long LL;
#define MAXN 110000
LL M[MAXN*4];LL lazy[MAXN*4];
void down(int x)
{
	if(lazy[x]!=-1)
	{
		M[x*2]=max(M[x*2],lazy[x]);
		M[x*2+1]=max(M[x*2+1],lazy[x]);
		lazy[x*2]=max(lazy[x],lazy[x*2]);
		lazy[x*2+1]=max(lazy[x],lazy[x*2+1]);
		lazy[x]=-1;
	}
}
void up(int x)
{
	M[x]=max(M[x*2],M[x*2+1]);
}
void cover(int now,int l,int r,int x,int y,LL v)
{
	//printf("%d %d\n",l,r);
	down(now);
	if(x<=l&&r<=y)
	{
		M[now]=v;lazy[now]=v;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)cover(now*2,l,mid,x,y,v);
	if(y>mid)cover(now*2+1,mid+1,r,x,y,v);
	up(now);
}
LL ask(int now,int l,int r,int x,int y)
{
	down(now);
	if(x<=l&&r<=y)return M[now];
	int mid=(l+r)>>1;LL res=0;
	if(x<=mid)res=max(res,ask(now*2,l,mid,x,y));
	if(y>mid)res=max(res,ask(now*2+1,mid+1,r,x,y));
	return res;
}
int main()
{
	memset(lazy,-1,sizeof lazy);
	int n,m;
	scanf("%d",&n);
	rep(i,1,n)
	{
		int v;scanf("%d",&v);
		cover(1,1,n,i,i,v);
		}
	scanf("%d",&m);
	rep(i,1,m)
	{
		//system("pause");
		int w,h;scanf("%d%d",&w,&h);
		LL res=ask(1,1,n,1,w);
		printf("%I64d\n",res);
		cover(1,1,n,1,w,h+res);
	}
	return 0;
}