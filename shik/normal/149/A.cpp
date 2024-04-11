// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int k,a[12],s=0,p=0;
	scanf("%d",&k);
	if ( k==0 ) { puts("0"); return 0; }
	for ( int i=0; i<12; i++ ) scanf("%d",a+i);
	sort(a,a+12);
	for ( p=11; p>=0; p-- ) if ( (s+=a[p])>=k ) break;
	printf("%d\n",p<0?-1:12-p);
	return 0;
}