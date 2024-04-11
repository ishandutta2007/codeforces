// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,a[7],p=0;
	scanf("%d",&n);
	for ( int i=0; i<7; i++ ) scanf("%d",a+i);
	while ( n>a[p%=7] ) n-=a[p++];
	printf("%d\n",p%7+1);
	return 0;
}