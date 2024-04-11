// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,x,c[10]={};
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) {
		scanf("%d",&x);
		c[x]++;
	}
	if ( !c[0] ) return puts("-1"),0;
	int all=0;
	for ( int i=0; i<10; i++ ) all+=i*c[i];
	for ( int i=0; i<10&&all%3; i++ ) if ( c[i] && (all-i)%3==0 ) c[i]--,all-=i,n--;
	for ( int i=0; i<10; i++ ) for ( int j=0; j<10&&all%3!=0; j++ ) if ( c[i] && c[j] && (i!=j||c[i]>1) && (all-i-j)%3==0 ) c[i]--,c[j]--,n-=2,all-=i+j;
	if ( c[0]==n ) return puts("0"),0;
	for ( int i=9; i>=0; i-- ) while ( c[i]-- ) printf("%d",i);
	puts("");
	return 0;
}