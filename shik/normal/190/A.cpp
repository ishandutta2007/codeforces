// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if ( n+m==0 ) puts("0 0");
	else if ( n==0 ) puts("Impossible");
	else printf("%d %d\n",max(n,m),n+max(0,m-1));
	return 0;
}