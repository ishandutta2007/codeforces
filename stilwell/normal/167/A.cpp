#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;

int n,i,j,k;
double a,d,v,ans,lastans;

int main()
{
	scanf("%d%lf%lf",&n,&a,&d);
	for(;n;--n)
	{
		scanf("%lf%lf",&ans,&v);
		if(v/a*v/2>d)ans+=sqrt(2*d/a);
		else ans+=v/a+(d-v/a*v/2)/v;
		if(ans<lastans)ans=lastans;
		printf("%.9lf\n",ans);
		lastans=ans;
	}
}