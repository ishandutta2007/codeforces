#include <cstdio>
#include <algorithm>
#define SI ({int x;scanf("%d",&x);x;})
using namespace std;

#define MXN 1000005

int a[1005];

int main()
{
	int i, n = SI, m = SI, k = SI, j, r = 0;
	
	for(i=1;i<=m;i++) a[i]=MXN;

	for(i=1;i<=n;i++)
	{
		j=SI, r=SI;
		if(r<a[j]) a[j]=r;
	}

	r = k;
	for(i=1;i<=n;i++)
	{
		if(a[i]<=k) k-=a[i];
		else k=0;
	}

	printf("%d\n",r-k);

	return 0;
}