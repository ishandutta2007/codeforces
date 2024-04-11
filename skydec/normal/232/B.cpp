#include<stdio.h>
#include<ctime>
#define jsb 1000000007
using namespace std;
typedef long long LL;
LL n,m,kp;
LL c[105][105];
LL f[105][10005];
LL Pows[105][105][2];
LL Pow(LL a,LL b)
{
	LL c=1;
	for(;b;b>>=1,a=a*a%jsb)
	if(b&1)c=c*a%jsb;
	return c;
}
void init()
{
	c[0][0]=1;
	for(int i=1;i<=100;i++)
	{
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;j++)
		c[i][j]=(c[i-1][j-1]+c[i-1][j])%jsb;
	}
	for(int i=0;i<=100;i++)
	for(int j=0;j<=100;j++)
	{
		Pows[i][j][0]=Pow(c[i][j],m/n);
		Pows[i][j][1]=Pow(c[i][j],m/n+1);
	}
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&kp);
	init();
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	for(int j=0;j<=i*n;j++)
	{
		for(int k=0;k<=n;k++)
		if(k<=j)
		{
			f[i][j]=(f[i][j]+f[i-1][j-k]*Pows[n][k][((m%n)>=i)]%jsb)%jsb;
		}
	}
	printf("%I64d\n",f[n][kp]);
	return 0;
}