#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,k;
int a[10010];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int cur=0,left=0;
	for(int i=1;i<=n;i++)
	{
		left+=a[i];
		int r=min(left,8);
		cur+=r;
		left-=r;
		if(cur>=k)
		{
			printf("%d\n",i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}