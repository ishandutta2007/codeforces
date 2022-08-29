#include<stdio.h>
#define MAXN 110000
using namespace std;
int l[MAXN],r[MAXN];
int n;
int down,up;
int main()
{
	scanf("%d",&n);
	down=1000000005;
	up=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		if(l[i]<down)down=l[i];
		if(r[i]>up)up=r[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(l[i]<=down&&r[i]>=up)
		{
			printf("%d\n",i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}