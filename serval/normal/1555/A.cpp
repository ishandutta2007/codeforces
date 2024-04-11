#include <cstdio>
#include <algorithm>
using namespace std;
int t;
long long n;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%lld",&n);
		printf("%lld\n",max((n+1)/2*5,15ll));
	}
	return 0;
}