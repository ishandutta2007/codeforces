// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int cal( int x, int k ) {
	int r=0;
	while ( x ) {
		r+=x;
		x/=k;
	}
	return r;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int L=1,R=n;
	while ( L!=R ) {
		int M=(L+R)/2;
		if ( cal(M,k)<n ) L=M+1;
		else R=M;
	}
	printf("%d\n",L);
	return 0;
}