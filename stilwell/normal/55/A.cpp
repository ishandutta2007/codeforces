#include <stdio.h>
#include <stdlib.h>
using namespace std;

int N,n,i,j,k,x;
bool vis[1005];

int main()
{
	scanf("%d",&n);
	N=n*n;x=0;
	for(i=1;i<=N;++i)
	{
		x+=i-1;
		x%=n;
		vis[x]=true;
	}
	for(i=0;i<n;++i)
	if(!vis[i]){printf("NO\n");return 0;}
	printf("YES\n");
}