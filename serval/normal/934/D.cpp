#include <cstdio>
using namespace std;
long long p,k;
long long r[20005];
int i,j;
int main()
{
	scanf("%I64d%I64d",&p,&k);
	while (p)
	{
		r[i]=p%(-k);
		p=p/(-k);
		while (r[i]<0)
		{
			r[i]=r[i]+k;
			p++;
		}
		i++;
	}
	if (i==0)
		i++;
	for (j=0;j<i;j++)
		if (r[j]>=k)
		{
			printf("-1\n");
			return 0;
		}
	printf("%d\n",i);
	for (j=0;j<i;j++)
		printf(j==i-1?"%I64d\n":"%I64d ",r[j]);
	return 0;
}