// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int r1,r2,c1,c2,d1,d2;
	scanf("%d%d%d%d%d%d",&r1,&r2,&c1,&c2,&d1,&d2);
	for ( int a=1; a<=9; a++ ) for ( int b=1; b<=9; b++ ) for ( int c=1; c<=9; c++ ) for ( int d=1; d<=9; d++ ) {
		if ( a==b || a==c || a==d || b==c || b==d || c==d ) continue;
		if ( a+b!=r1 || c+d!=r2 ) continue;
		if ( a+c!=c1 || b+d!=c2 ) continue;
		if ( a+d!=d1 || b+c!=d2 ) continue;
		printf("%d %d\n%d %d\n",a,b,c,d);
		return 0;
	}
	puts("-1");
	return 0;
}