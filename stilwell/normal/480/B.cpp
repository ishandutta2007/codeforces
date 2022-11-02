#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n,l,x,y,i,j,k;
int a[100005];
bool rx,ry;

set <int> app,app2;

int main()
{
	scanf("%d%d%d%d",&n,&l,&x,&y);
	for(i=1;i<=n;++i)scanf("%d",&a[i]),app.insert(a[i]);
	rx=ry=false;
	for(i=1;i<=n;++i)
	if(app.find(a[i]-x)!=app.end())
	rx=true;
	for(i=1;i<=n;++i)
	if(app.find(a[i]-y)!=app.end())
	ry=true;
	if(rx&&ry)
	{
		printf("0\n");
		return 0;
	}
	if(rx)
	{
		printf("1\n");
		printf("%d\n",y);
		return 0;
	}
	if(ry)
	{
		printf("1\n");
		printf("%d\n",x);
		return 0;
	}
	for(i=1;i<=n;++i)
	{
		if(a[i]>=x)app2.insert(a[i]-x);
		if(a[i]+x<=l)app2.insert(a[i]+x);
	}
	for(i=1;i<=n;++i)
	{
		if(app2.find(a[i]-y)!=app2.end())
		{
			printf("1\n");
			printf("%d\n",a[i]-y);
			return 0;
		}
		if(app2.find(a[i]+y)!=app2.end())
		{
			printf("1\n");
			printf("%d\n",a[i]+y);
			return 0;
		}
	}
	printf("2\n");
	printf("%d %d\n",x,y);
}