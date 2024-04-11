// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,m,s,a,b,c,d;
	scanf("%d%d%d",&n,&m,&s);
	a=(n%s==0?s:n%s);
	b=(m%s==0?s:m%s);
	c=(n+s-1)/s;
	d=(m+s-1)/s;
	printf("%I64d\n",1LL*a*b*c*d);
	return 0;
}