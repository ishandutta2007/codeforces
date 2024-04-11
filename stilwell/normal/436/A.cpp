#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,x,a,b,i,j,k,lim,ans1,ans2,Max;

struct node
{
	int t,h,x;
}t[2005];
inline bool cmp(const node &a,const node &b){return a.h<b.h;}

bool use[2005];

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d%d%d",&t[i].t,&t[i].h,&t[i].x);
	sort(t+1,t+n+1,cmp);
	x=m;lim=0;t[0].x=-1;
	for(i=1;i<=n;++i)
	{
		while(lim<n&&t[lim+1].h<=x)++lim;
		Max=0;
		for(j=1;j<=lim;++j)if(t[j].t==i%2&&!use[j]&&t[j].x>t[Max].x)Max=j;
		if(!Max)break;
		x+=t[Max].x;use[Max]=true;
	}
	ans1=i-1;
	for(i=1;i<=n;++i)use[i]=false;
	x=m;lim=0;t[0].x=-1;
	for(i=1;i<=n;++i)
	{
		while(lim<n&&t[lim+1].h<=x)++lim;
		Max=0;
		for(j=1;j<=lim;++j)if(t[j].t!=i%2&&!use[j]&&t[j].x>t[Max].x)Max=j;
		if(!Max)break;
		x+=t[Max].x;use[Max]=true;
	}
	ans2=i-1;
	printf("%d\n",max(ans1,ans2));
}