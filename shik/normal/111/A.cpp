// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	long long x,y;
	scanf("%d%I64d%I64d",&n,&x,&y);
	if ( n>y || (y-n+1)*(y-n+1)+(n-1)<x ) puts("-1");
	else {
		printf("%I64d",y-n+1);
		for ( int i=1; i<n; i++ ) printf(" %d",1);
		puts("");
	}
	return 0;
}