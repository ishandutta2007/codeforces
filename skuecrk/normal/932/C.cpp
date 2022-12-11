#include<cstdio>
int main()
{
	int n,a,b,i,j,k;
	scanf("%d%d%d",&n,&a,&b);
	for(i=0;i*a<=n;++i)if((n-i*a)%b==0)
	{
		for(j=0;j<i;++j)
		{
			for(k=1;k<a;++k)printf("%d ",j*a+k+1);
			printf("%d ",j*a+1);
		}
		for(j=0;j<(n-i*a)/b;++j)
		{
			for(k=1;k<b;++k)printf("%d ",i*a+j*b+k+1);
			printf("%d ",i*a+j*b+1);
		}
		return 0;
	}
	puts("-1");
}