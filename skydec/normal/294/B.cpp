#include<stdio.h>
#include<cstring>
using namespace std;
bool f[2][225][11005];
long n,m;
long a[105];long b[105];
int main()
{
	scanf("%ld",&n);
	for(long i=1;i<=n;i++)scanf("%ld%ld",&a[i],&b[i]);
	f[0][0][0]=true;long now=0;
	for(long i=1;i<=n;i++)
	{
		now^=1;memset(f[now],false,sizeof f[now]);
		for(long k=0;k<=200;k++)
		for(long s=0;s<=10000;s++)
		if(f[now^1][k][s])
		{
			f[now][a[i]+k][s]=true;
			f[now][k][b[i]+s]=true;
		}
	}
	for(long i=1;i<=200;i++)
	{
		for(long j=0;j<=i;j++)
		if(f[now][i][j]){printf("%ld\n",i);return 0;}
	}
	return 0;
}