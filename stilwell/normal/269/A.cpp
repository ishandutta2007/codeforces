#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,i,j,k;
long long x,y;

struct node
{
	int a,b;
}t[100005];
inline bool cmp(const node &a,const node &b){return a.a<b.a;}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d%d",&t[i].a,&t[i].b);
	sort(t+1,t+n+1,cmp);
	for(i=1;i<=n;++i)
	{
		while(x<t[i].a&&y>1)++x,y=y/4+(y%4!=0);
		x=t[i].a;
		if(t[i].b>y)y=t[i].b;
	}
	if(y==1){printf("%I64d\n",x+1);return 0;}
	while(y>1)++x,y=y/4+(y%4!=0);
	printf("%I64d\n",x);
}