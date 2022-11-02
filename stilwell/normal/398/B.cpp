#include <stdio.h>
#include <stdlib.h>
using namespace std;

double f[2005][2005];
int n,m,A,B,i,j,k,u,v;
bool x[2005],y[2005];

int main()
{
	scanf("%d%d",&n,&m);
	for(;m;--m)
	{
		scanf("%d%d",&u,&v);
		if(!x[u])x[u]=true,++A;
		if(!y[v])y[v]=true,++B;
	}
	for(i=n;i>=A;--i)
	for(j=n;j>=B;--j)
	if(i!=n||j!=n)
	f[i][j]=(n*n+f[i+1][j+1]*(n-i)*(n-j)+f[i+1][j]*(n-i)*j+f[i][j+1]*i*(n-j))/(n*n-i*j);
	printf("%.20lf\n",f[A][B]);
}