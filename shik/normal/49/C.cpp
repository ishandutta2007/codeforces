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
	for ( int i=2; i<=n; i++ ) printf("%d ",i);
	puts("1");
	return 0;
}