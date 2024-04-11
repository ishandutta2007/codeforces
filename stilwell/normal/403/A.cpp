#include <stdio.h>
#include <stdlib.h>
using namespace std;

int T,n,p,q,i,j,k,num,sum;
bool edge[50][50];

int main()
{
	scanf("%d",&T);
	for(;T;--T)
	{
		scanf("%d%d",&n,&p);
		for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
		edge[i][j]=false;
		q=p+2*n;
		//if(q>n*(n-1)/2)printf("data error\n");
		for(i=1;i<=n;++i)
		for(j=i+1;j<=n;++j)
		if(q)
		{
			edge[i][j]=true;
			--q;
		}
		for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
		if(edge[i][j])
		printf("%d %d\n",i,j);
		/*for(i=(1<<n)-1;i>=1;--i)
		{
			num=sum=0;
			for(j=0;j<n;++j)if(i&(1<<j))++num;
			for(j=1;j<=n;++j)
			for(k=1;k<=n;++k)
			if(edge[j][k])
			if(i&(1<<j-1))
			if(i&(1<<k-1))
			++sum;
			if(sum>2*num+p)
			printf("check error\n");
		}*/
	}
}