// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
const int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int d1,m1,y1;
bool ok( int d2, int m2, int y2 ) {
	if ( m2<1 || m2>12 ) return 0;
	if ( d2<1 || d2>mon[m2]+(y2%4==0) ) return 0;
	if ( y2+18!=y1 ) return y2+18<y1;
	if ( m1!=m2 ) return m2<m1;
	return d2<=d1;
}
int main()
{
	scanf("%d.%d.%d",&d1,&m1,&y1);
	int s[3];
	scanf("%d.%d.%d",s,s+1,s+2);
	sort(s,s+3);
	do {
		if ( ok(s[0],s[1],s[2]) ) return puts("YES"),0;
	} while ( next_permutation(s,s+3) );
	puts("NO");
	return 0;
}