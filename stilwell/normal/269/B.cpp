#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k;
int f[5005];

struct node
{
	int a;double b;
}t[5005];
inline bool cmp(const node &a,const node &b){return a.b<b.b;}

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d%lf",&t[i].a,&t[i].b);
	sort(t+1,t+n+1,cmp);
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)f[j]+=(t[i].a!=j);
		for(j=1;j<m;++j)if(f[j]<f[j+1])f[j+1]=f[j];
	}
	printf("%d\n",f[m]);
}