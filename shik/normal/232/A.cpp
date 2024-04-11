// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 110
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int e[N][N];
int main()
{
	int n=0,m,k;
	scanf("%d",&k);
	while ( k>0 ) {
		for ( m=n; m*(m-1)/2>k; m-- );
		for ( int i=0; i<m; i++ ) e[n][i]=e[i][n]=1;
		k-=m*(m-1)/2;
		n++;
	}
	printf("%d\n",n);
	for ( int i=0; i<n; i++,puts("") ) for ( int j=0; j<n; j++ ) printf("%d",e[i][j]);
	return 0;
}