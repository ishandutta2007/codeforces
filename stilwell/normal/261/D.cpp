#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int T,n,b,t,i,j,k;
int a[100005],f[100005];

int main()
{
	scanf("%d%d%d%d",&T,&n,&b,&t);
	if(t>n)t=n;if(t>b)t=b;
	for(;T;--T)
	{
		memset(f,0,sizeof(f));
		for(i=1;i<=n;++i)scanf("%d",&a[i]);
		for(i=1;i<=t;++i)
		for(j=1;j<=n;++j)
		{
			f[a[j]]=f[a[j]-1]+1;
			for(k=a[j]+1;k<=b&&f[k]<f[a[j]];++k)f[k]=f[a[j]];
		}
		printf("%d\n",f[b]);
	}
}