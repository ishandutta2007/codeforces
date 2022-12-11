#include<cstdio>
using namespace std;

int n,k;

int main()
{
	scanf("%d%d",&n,&k);
	if (k==n) {printf("-1\n");return 0;}
	for (int i=1;i<n-k;i++) printf("%d ",i+1);
	printf("1 ");
	for (int i=n-k+1;i<=n;i++) printf("%d ",i);
	printf("\n");
}