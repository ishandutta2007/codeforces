#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int T,n,i,j,k;
int a[105];
long long x,fib[105],f[88][5][5];

int main()
{
	fib[1]=1;fib[2]=2;
	for(n=3;;++n)
	{
		fib[n]=fib[n-1]+fib[n-2];
		if(fib[n]>1000000000000000000ll)break;
	}
	scanf("%d",&T);
	for(;T;--T)
	{
		memset(f,0,sizeof(f));
		for(i=1;i<=n;++i)a[i]=0;
		scanf("%I64d",&x);
		for(i=n;i>=1;--i)
		if(x>=fib[i])x-=fib[i],a[i]=1;
		f[n][0][0]=1;
		for(i=n;i>=1;--i)
		for(j=0;j<=3;++j)
		for(k=0;k<=3;++k)
		{
			if(j+a[i]+k<=n)f[i-1][j+a[i]+k][j+a[i]]+=f[i][j][k];
			if(j+a[i]+k>=1&&j+a[i]+k-1<=n)f[i-1][j+a[i]+k-1][j+a[i]-1]+=f[i][j][k];
		}
		printf("%I64d\n",f[0][0][0]);
	}
}