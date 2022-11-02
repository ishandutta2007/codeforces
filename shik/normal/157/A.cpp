// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 33
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,t,r[N]={},c[N]={},ans=0;
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) for ( int j=0; j<n; j++ ) {
		scanf("%d",&t);
		r[i]+=t;
		c[j]+=t;
	}
	for ( int i=0; i<n; i++ ) for ( int j=0; j<n; j++ ) if ( c[j]>r[i] ) ans++;
	printf("%d\n",ans);
	return 0;
}