#include <cstdio>
using namespace std;
long long n,k;
long long c(long long v)
{
	return (v+k-1)/k;
}
int main()
{
	scanf("%lld%lld",&n,&k);
	printf("%lld\n",c(2*n)+c(5*n)+c(8*n));
	return 0;
}