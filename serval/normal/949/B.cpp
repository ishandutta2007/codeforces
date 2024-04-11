#include <cstdio>
using namespace std;
long long n,u;
int q;
int main()
{
	scanf("%I64d%d",&n,&q);
	while (q--)
	{
		scanf("%I64d",&u);
		while (u&1^1)
			u=u/2+n;
		printf("%I64d\n",u/2+1);
	}
	return 0;
}