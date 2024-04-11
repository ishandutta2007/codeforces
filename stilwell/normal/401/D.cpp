#include <stdio.h>
#include <stdlib.h>
using namespace std;

long long N;
int d[100],num[10],n,m,p,i,j,k;
long long f[1<<18][100];

int main()
{
	scanf("%I64d%d",&N,&m);
	for(;N;N/=10)d[++n]=N%10,++num[N%10];
	p=1<<n;--p;
	f[0][0]=1;
	for(i=0;i<=p;++i)
	for(j=1;j<=n;++j)
	if(((i&(1<<j-1))==0)&&(d[j]!=0||i!=0))
	for(k=0;k<m;++k)
	if(f[i][k])
	f[i|(1<<j-1)][(k*10+d[j])%m]+=f[i][k];
	N=f[p][0];
	for(i=0;i<=9;++i)
	for(j=num[i];j;--j)
	N/=j;
	printf("%I64d\n",N);
}