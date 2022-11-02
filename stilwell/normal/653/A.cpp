#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,i,j,k;
int a[100005];

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&k),++a[k];
	for(i=1;i<=1000;++i)
	if(a[i]&&a[i+1]&&a[i+2])
	{
		printf("YES\n");
		return 0;
	}
	printf("NO\n");
}