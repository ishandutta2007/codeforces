#include<cstdio>
#define MX 1000000
int g[MX+5],s[10][MX+5];
int main()
{
	int q,i,j,k;
	for(i=1;i<=MX;++i)
	{
		if(i<10){g[i]=i;continue;}
		for(j=i,k=1;j;j/=10)if(j%10)k*=j%10;
		g[i]=g[k];
	}
	for(i=1;i<10;++i)for(j=1;j<=MX;++j)s[i][j]=s[i][j-1]+(g[j]==i);
	for(scanf("%d",&q);q--;)
	{
		scanf("%d%d%d",&i,&j,&k);
		printf("%d\n",s[k][j]-s[k][i-1]);
	}
}