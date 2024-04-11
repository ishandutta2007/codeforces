// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,x[110],d[110];
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) scanf("%d%d",x+i,d+i);
	for ( int i=0; i<n; i++ )
		for ( int j=0; j<n; j++ )
			if ( i!=j && x[i]+d[i]==x[j] && x[j]+d[j]==x[i] ) {
				puts("YES");
				return 0;
			}
	puts("NO");
	return 0;
}