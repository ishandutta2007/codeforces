#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,i,j,k;
int u[1000005],v[1000005],tot;

struct node
{
	int a,id;
}t[1005];
inline bool cmp(const node &a,const node &b){return a.a<b.a;}

void merge(int x,int y){u[++tot]=t[x].id;v[tot]=t[y].id;t[y].a-=t[x].a;t[x].a+=t[x].a;}
void work()
{
	int a=t[2].a%t[1].a,b=t[2].a/t[1].a;
	for(;b;b>>=1)if(b&1)merge(1,2);else merge(1,3);
	sort(t+1,t+4,cmp);
	if(!a)t[1]=t[2],t[2]=t[3];else work();
}

int main()
{
	scanf("%d",&n);
	for(i=n,n=j=0;i;--i)
	{
		scanf("%d",&k);++j;
		if(k)t[++n].a=k,t[n].id=j;
	}
	if(n<2){printf("-1\n");return 0;}
	sort(t+1,t+n+1,cmp);
	for(i=3;i<=n;++i)
	{
		t[3]=t[i];
		sort(t+1,t+4,cmp);
		work();
	}
	printf("%d\n",tot);
	for(i=1;i<=tot;++i)printf("%d %d\n",u[i],v[i]);
}