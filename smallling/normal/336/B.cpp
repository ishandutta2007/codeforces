#include<cstdio>
#include<cmath>

int n,r,i;

double ans,f[100001],c[100001];

int main()
{
	scanf("%d%d",&n,&r);
	f[0]=2.0*r;
	f[1]=2.0*r+sqrt(2)*r;
	f[2]=2.0*r+sqrt(2)*r*2;
	for(i=3;i<n;i++)
	f[i]=f[i-1]+2*r;
	c[0]=f[0];
	for(i=1;i<n;i++)
	c[i]=f[i]+c[i-1];
	for(i=1;i<=n;i++)
	ans+=c[i-1]+c[n-i]-c[0];
	ans/=n*1.0;
	ans/=n*1.0;
	printf("%.10lf",ans);
}