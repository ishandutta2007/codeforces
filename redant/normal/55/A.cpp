#include <cstdio>
int main()
{
	int n; scanf("%d",&n);
	printf( (n&(n-1)) ? "NO\n" : "YES\n" );
	return 0;
}