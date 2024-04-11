// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int sol[1010][1010];
int main()
{
	int n,m;
	scanf("%d",&n);
	m=n;
	while ( m*(m-1)/2>n ) m--;
	printf("%d\n",m);
	int c1=0,c2=0;
	for ( int i=1; i<=m; i++ ) for ( int j=i; j<m; j++ ) sol[i][j]=++c1;
	for ( int i=1; i<m; i++ ) for ( int j=i+1; j<=m; j++ ) sol[j][i]=++c2;
	for ( int i=1; i<=m; i++ ) for ( int j=1; j<m; j++ ) printf("%d%c",sol[i][j],j==m-1?'\n':' ');
	return 0;
}
/*
123
145
246
356
*/