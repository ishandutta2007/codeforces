#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,x;
int delta[100005],pre[100005];

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&x);
		if(pre[x])
		{
			if(delta[x])
			{
				if(i-pre[x]!=delta[x])
				delta[x]=-1;
			}else delta[x]=i-pre[x];
		}
		pre[x]=i;
	}
	for(i=1;i<=100000;++i)
	if(pre[i]&&delta[i]!=-1)
	++m;
	printf("%d\n",m);
	for(i=1;i<=100000;++i)
	if(pre[i]&&delta[i]!=-1)
	printf("%d %d\n",i,delta[i]);
}