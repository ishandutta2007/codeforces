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
typedef int INT;
#define int LL
#define MAXN 1005
struct car
{
	int x,y,d;
}data[MAXN*MAXN];int tot=0;
int n,m;long long ans=0;
inline LL calc(LL a,LL b,LL c,int x)
{
	return a*x*x+b*x+c;
}
int calcx()
{
	long long A,B,C;A=B=C=0;
	for(int i=1;i<=tot;i++)C+=data[i].x*1ll*data[i].x*data[i].d;
	for(int i=1;i<=tot;i++)B-=2ll*data[i].x*data[i].d;
	for(int i=1;i<=tot;i++)A+=1ll*data[i].d;
	long long ss=(LL)1e16;int dd=-1;
	for(int x=0;x<=4*n;x+=4)
	if((dd==-1)||calc(A,B,C,x)<ss)
	{
		ss=calc(A,B,C,x);
		dd=x;
	}
	ans+=ss;
	return dd;
}
int calcy()
{
	long long A,B,C;A=B=C=0;
	for(int i=1;i<=tot;i++)C+=data[i].y*1ll*data[i].y*data[i].d;
	for(int i=1;i<=tot;i++)B-=2ll*data[i].y*data[i].d;
	for(int i=1;i<=tot;i++)A+=1ll*data[i].d;
	
	long long ss=(LL)1e16;int dd=-1;
	for(int x=0;x<=4*m;x+=4)
	if((dd==-1)||calc(A,B,C,x)<ss)
	{
		ss=calc(A,B,C,x);
		dd=x;
	}
	ans+=ss;
	return dd;
}
INT main()
{
	scanf("%I64d%I64d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		int v;scanf("%I64d",&v);
		if(v)
		{
			tot++;
			data[tot].x=4*i-2;
			data[tot].y=4*j-2;
			data[tot].d=v;
		}
	}
	int dx=calcx();
	int dy=calcy();
	printf("%I64d\n%I64d %I64d\n",ans,dx/4,dy/4);
	return 0;	
}