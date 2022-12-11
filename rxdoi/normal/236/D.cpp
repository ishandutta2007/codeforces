#include<cstdio>
using namespace std;

int n;
double t,Ans,Len;

int main()
{
	scanf("%d",&n);
	while (n--)
	{
		scanf("%lf",&t);
		Ans+=t*(2*Len+1);
		Len=(Len+1)*t;
	}
	printf("%.10lf\n",Ans);
}