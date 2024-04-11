// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	for ( int i=0; i<=1000; i++ ) for ( int j=0; j<=1000; j++ ) if ( i*i+j==n && i+j*j==m ) ans++;
	printf("%d\n",ans);
	return 0;
}