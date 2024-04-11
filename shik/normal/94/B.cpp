// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int m,e[10][10]={},a,b;
	scanf("%d",&m);
	while ( m-- ) {
		scanf("%d%d",&a,&b);
		e[a][b]=e[b][a]=1;
	}
	for ( int i=1; i<=5; i++ )
		for ( int j=i+1; j<=5; j++ )
			for ( int k=j+1; k<=5; k++ )
				if ( e[i][j]==e[j][k] && e[j][k]==e[k][i] ) {
					puts("WIN");
					return 0;
				}
	puts("FAIL");
	return 0;
}