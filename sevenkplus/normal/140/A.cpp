#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int n,x,y;
	scanf("%d%d%d",&n,&y,&x);
	if(x>y)puts("NO");else
	if(x*2>y)if(n>1)puts("NO");else puts("YES");else
	{
		double z=asin((double)x/(y-x))*2;
		if(z*n<2*M_PI+1e-12)puts("YES");else puts("NO");
	}
	return 0;
}