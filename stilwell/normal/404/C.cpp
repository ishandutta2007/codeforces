#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k,tot,x,y;
int u[100005],v[100005];
int d[100005],sum[100005];

struct node
{
	int d,id;
}t[100005];

inline bool cmp(const node &a,const node &b){return a.d<b.d;}
void addedge(int x,int y){++tot;u[tot]=x;v[tot]=y;++sum[x];++sum[y];}

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",&t[i].d),t[i].id=i;
	sort(t+1,t+n+1,cmp);
	for(i=1;i<=n;++i)
	if(!d[t[i].d])d[t[i].d]=i;
	t[0].d=-1;
	for(i=1;i<=n;++i)
	if(t[i].d)
	{
		x=d[t[i].d-1];
		while(sum[t[x].id]==m)x=++d[t[i].d-1];
		if(t[x].d!=t[i].d-1)
		{
			printf("-1\n");
			return 0;
		}
		addedge(t[x].id,t[i].id);
		if(sum[t[x].id]==m)++d[t[i].d-1];
	}
	else
	{
		if(i>1)
		{
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n",tot);
	for(i=1;i<=tot;++i)printf("%d %d\n",u[i],v[i]);
}