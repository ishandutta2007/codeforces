#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,m,a,b;
double ans=1298472199893.0;
int main()
{
	scanf("%d%d",&n,&m);
	while(n--)
	{
		scanf("%d%d",&a,&b);
		if(1.0*m*a/b<ans)ans=1.0*m*a/b;
	}
	printf("%.9lf\n",ans);
	return 0;
}