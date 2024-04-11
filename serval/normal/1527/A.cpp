#include <cstdio>
using namespace std;
int n;
int k;
int main()
{
	scanf("%d",&n);
	while (n--)
	{
		scanf("%d",&k);
		printf("%d\n",(1<<(31-__builtin_clz(k)))-1);
	}
	return 0;
}