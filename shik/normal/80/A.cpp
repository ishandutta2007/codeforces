// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool isp( int x ) {
	if ( x<2 ) return 0;
	for ( int i=2; i<x; i++ )
		if ( x%i==0 ) return 0;
	return 1;
}
int main()
{
	int n,m,i;
	scanf("%d%d",&n,&m);
	for ( i=n+1; i<m; i++ )
		if ( isp(i) ) {
			puts("NO");
			return 0;
		}
	puts(isp(m)?"YES":"NO");
	return 0;
}