#include<cstdio>
#include<algorithm>
using namespace std;

int n,p,k;

int main()
{
	scanf("%d%d%d",&n,&p,&k);
	if (p-k>1) printf("<< ");
	for (int i=max(p-k,1);i<=min(p+k,n);i++)
		if (i==p) printf("(%d) ",i);else printf("%d ",i);
	if (p+k<n) printf(">>");printf("\n");
}