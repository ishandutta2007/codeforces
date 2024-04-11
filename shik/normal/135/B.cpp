// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
struct P {
	int x,y;
	P( int _x=0, int _y=0 ):x(_x),y(_y){}
	void read() { scanf("%d%d",&x,&y); }
	int len2() { return x*x+y*y; }
	void print() { printf("(%d,%d)\n",x,y); }
} p[8];
P operator -( P a, P b ) { return P(a.x-b.x,a.y-b.y); }
int operator *( P a, P b ) { return a.x*b.y-a.y*b.x; }
int operator ^( P a, P b ) { return a.x*b.x+a.y*b.y; }
int dis2( P a, P b ) { return (a-b).len2(); }
int X( P o, P a, P b ) { return (a-o)*(b-o); }
int dot( P o, P a, P b ) { return (a-o)^(b-o); }
bool chk_sqr( P a, P b, P c, P d ) {
	if ( dis2(a,b)!=dis2(b,c) ) return 0;
	if ( dis2(a,b)!=dis2(c,d) ) return 0;
	if ( dis2(a,b)!=dis2(d,a) ) return 0;
	if ( dis2(a,c)!=dis2(b,d) ) return 0;
	if ( dis2(a,b)==0 ) return 0;
	if ( dot(b,a,c)!=0 ) return 0;
	if ( dot(c,b,d)!=0 ) return 0;
	if ( dot(d,c,a)!=0 ) return 0;
	if ( dot(a,d,b)!=0 ) return 0;
	return 1;
}
bool chk_rec( P a, P b, P c, P d ) {
	if ( dis2(a,b)!=dis2(c,d) ) return 0;
	if ( dis2(b,c)!=dis2(a,d) ) return 0;
	if ( dis2(a,c)!=dis2(b,d) ) return 0;
	if ( dis2(a,b)==0 ) return 0;
	if ( dis2(b,c)==0 ) return 0;
	if ( dot(b,a,c)!=0 ) return 0;
	if ( dot(c,b,d)!=0 ) return 0;
	if ( dot(d,c,a)!=0 ) return 0;
	if ( dot(a,d,b)!=0 ) return 0;
	return 1;
}
int main()
{
	for ( int i=0; i<8; i++ ) p[i].read();
	int s[8]={0,1,2,3,4,5,6,7};
	do {
		if ( !chk_sqr(p[s[0]],p[s[1]],p[s[2]],p[s[3]]) ) continue;
		if ( !chk_rec(p[s[4]],p[s[5]],p[s[6]],p[s[7]]) ) continue;
		puts("YES");
		for ( int i=0; i<4; i++ ) printf("%d%c",s[i]+1,i==3?'\n':' ');
		for ( int i=4; i<8; i++ ) printf("%d%c",s[i]+1,i==7?'\n':' ');
		return 0;
	} while ( next_permutation(s,s+8) );
	puts("NO");
	return 0;
}