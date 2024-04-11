// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	puts("307");
	puts("0 1000000");
	for ( int i=1; i<=305; i++ ) printf("%d %d\n",250000+i*1305,310-i);
	puts("900000 1000000");
	return 0;
}