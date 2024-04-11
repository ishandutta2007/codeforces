// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",n);
	for ( int i=1; i<n; i++ ) printf(" %d",i);
	puts("");
	return 0;
}