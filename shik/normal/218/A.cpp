// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,k,h[310];
	scanf("%d%d",&n,&k);
	for ( int i=1; i<=2*n+1; i++ ) scanf("%d",h+i);
	for ( int i=2; i<=2*n&&k>0; i+=2 ) if ( h[i]-1>h[i-1] && h[i]-1>h[i+1] ) h[i]--,k--;
	for ( int i=1; i<=2*n+1; i++ ) printf("%d%c",h[i],i==2*n+1?'\n':' ');
	return 0;
}