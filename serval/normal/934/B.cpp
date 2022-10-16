#include <cstdio>
using namespace std;
int k;
long long ret;
int main()
{
	scanf("%d",&k);
	if (k>36)
		printf("-1\n");
	else
	{
		while (k>1)
		{
			k-=2;
			ret=ret*10+8;
		}
		if (k==1)
		{
			k--;
			ret=ret*10+6;
		}
		printf("%I64d\n",ret);
	}
	return 0;
}