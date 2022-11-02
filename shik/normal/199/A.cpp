// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int f[50]={0,1};
	for ( int i=2; i<50; i++ ) f[i]=f[i-1]+f[i-2];
	int n;
	scanf("%d",&n);
	for ( int i=0; i<50; i++ ) for ( int j=0; j<50; j++ ) for ( int k=0; k<50; k++ )
		if ( f[i]+f[j]+f[k]==n ) return printf("%d %d %d\n",f[i],f[j],f[k]),0;
	puts("I'm too stupid to solve this problem");
	return 0;
}