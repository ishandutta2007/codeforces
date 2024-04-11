#include <cstdio>
using namespace std;
long long n,k,a;
int i;
long long ans,ansx,ansy;
int main()
{
	scanf("%I64d%I64d",&n,&k);
	for (i=1;i<=k;i++)
	{
		scanf("%I64d",&a);
		if (n-n%a>=ans)
		{
			ans=n-n%a;
			ansx=i;
			ansy=n/a;
		}
	}
	printf("%I64d %I64d\n",ansx,ansy);
	return 0;
}