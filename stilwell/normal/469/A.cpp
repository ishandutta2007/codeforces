#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,i,j,k;
bool a[105];

int main()
{
	scanf("%d",&n);
	scanf("%d",&i);
	for(;i;--i)scanf("%d",&k),a[k]=true;
	scanf("%d",&i);
	for(;i;--i)scanf("%d",&k),a[k]=true;
	for(i=1;i<=n;++i)if(!a[i]){printf("Oh, my keyboard!\n");return 0;}
	printf("I become the guy.\n");
}