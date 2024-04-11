// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,m,x;
	scanf("%d%d%d",&n,&m,&x);
	while ( n>2 && m>2 && x>1 ) n-=2,m-=2,x--;
	if ( x>1 ) puts("0");
	else printf("%d\n",(n*m+1)/2-(max(0,(n-2))*max(0,(m-2))+1)/2);
	return 0;
}