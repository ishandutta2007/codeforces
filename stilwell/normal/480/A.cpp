#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n,i,j,k,ans;

struct node
{
	int a,b;
}t[5005];
inline bool cmp(const node &a,const node &b)
{
	if(a.a!=b.a)return a.a<b.a;
	return a.b<b.b;
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d%d",&t[i].a,&t[i].b);
	sort(t+1,t+n+1,cmp);
	for(i=1;i<=n;++i)if(t[i].b<ans)ans=t[i].a;else ans=t[i].b;
	printf("%d\n",ans);
}