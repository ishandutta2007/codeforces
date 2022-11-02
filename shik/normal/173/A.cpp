// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
const char t[]="RSPR";
int pk( char a, char b ) {
	for ( int i=0; i<3; i++ ) {
		if ( a==t[i] && b==t[i+1] ) return 1;
		if ( b==t[i] && a==t[i+1] ) return 2;
	}
	return 0;
}
int main()
{
	int n,n1,n2,cnt[3]={};
	char a[1010],b[1010];
	scanf("%d %s %s",&n,a,b);
	n1=strlen(a); n2=strlen(b);
	if ( n>=n1*n2 ) for ( int i=0; i<n1*n2; i++ ) cnt[pk(a[i%n1],b[i%n2])]++;
	for ( int i=0; i<3; i++ ) cnt[i]*=n/(n1*n2);
	n%=n1*n2;
	for ( int i=0; i<n; i++ ) cnt[pk(a[i%n1],b[i%n2])]++;
	printf("%d %d\n",cnt[2],cnt[1]);
	return 0;
}