#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k;
char opt[15];
double ans;

double Power(double a,int b)
{
	double ans=1;
	while(b)
	{
		if(b%2)ans=ans*a;
		a=a*a;
		b/=2;
	}
	return ans;
}

int main()
{
	scanf("%s",opt);
	scanf("%d%d",&n,&m);
	if(opt[0]=='A')
	{
		ans=n;
		for(i=1;i<=m;++i)
		for(j=1;j<=n;++j)
		ans+=(n-j)*Power(0.5,2*i)*Power(1-Power(0.5,i),j-1)*(Power(2,i)-Power(2,i-1)*(1+(j-1)/(Power(2,i)-1)));
		printf("%.20lf\n",ans);
	}
	else printf("%d\n",n);
}