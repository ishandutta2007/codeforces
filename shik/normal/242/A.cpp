// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int x,y,a,b,p[10000],q[10000],n=0;
	scanf("%d%d%d%d",&x,&y,&a,&b);
	for ( int i=a; i<=x; i++ ) for ( int j=b; j<=y; j++ ) if ( i>j ) { p[n]=i; q[n]=j; n++; }
	printf("%d\n",n);
	for ( int i=0; i<n; i++ ) printf("%d %d\n",p[i],q[i]);
	return 0;
}