// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int n1=n/2,n2=n-n1;
	printf("%d\n",n1*n2);
	for ( int i=1; i<=n1; i++ ) for ( int j=1; j<=n2; j++ ) printf("%d %d\n",i,n1+j);
	return 0;
}