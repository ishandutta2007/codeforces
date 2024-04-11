#include <stdio.h>
#include <stdlib.h>
using namespace std;

int prime[10000005],p[10000005],tot;
int num[10000005];
long long sum[10000005];
int n,a,i,j,k,l,r;

int main()
{
	for(i=2;i<=10000000;++i)
	{
		if(p[i]==0)prime[++tot]=p[i]=i;
		num[i]=tot;
		for(j=1;(prime[j]<=10000000/i)&&(prime[j]<=p[i])&&(j<=tot);++j)p[prime[j]*i]=prime[j];
	}
	scanf("%d",&n);
	for(;n;--n)
	{
		scanf("%d",&a);k=0;
		for(;a>1;a/=p[a])
		if(p[a]!=k)++sum[num[p[a]]],k=p[a];
	}
	for(i=1;i<=tot;++i)sum[i]+=sum[i-1];
	scanf("%d",&n);
	for(;n;--n)
	{
		scanf("%d%d",&l,&r);
		if(l>10000000){printf("0\n");continue;}
		if(r>10000000)r=10000000;
		printf("%I64d\n",sum[num[r]]-sum[num[l-1]]);
	}
}