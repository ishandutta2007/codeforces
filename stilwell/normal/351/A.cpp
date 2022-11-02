#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int N,n,i,j,k;
double b,a[4005],ans,tmp;

double Abs(double x){if(x<0)return -x;return x;}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n+n;++i)
	{
		scanf("%lf",&b);
		b-=(int)b;tmp+=b;
		if(b>0.0001)++N;
	}
	ans=100000000;
	for(i=N-n;i<=n;++i)ans=min(ans,Abs(i-tmp));
	printf("%.3lf\n",ans);
}