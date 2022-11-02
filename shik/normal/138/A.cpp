// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define L 10010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
bool is_vow( char c ) { return c=='a' || c=='e' || c=='i' || c=='o' || c=='u'; }
int get( char *s, int k ) {
	int r=strlen(s);
	while ( k-- && r>=0 ) {
		r--;
		while ( r>=0 && !is_vow(s[r]) ) r--;
	}
	return r;
}
char s[4][L];
int main()
{
	int n,k,ans=7,p[4];
	scanf("%d%d",&n,&k);
	while ( n-- ) {
		for ( int i=0; i<4; i++ ) scanf("%s",s[i]);
		for ( int i=0; i<4; i++ ) p[i]=get(s[i],k);
		if ( p[0]<0 || p[1]<0 || p[2]<0 || p[3]<0 ) { ans=0; break; }
		int now=0;
		if ( !strcmp(s[0]+p[0],s[1]+p[1]) && !strcmp(s[2]+p[2],s[3]+p[3]) ) now|=1;
		if ( !strcmp(s[0]+p[0],s[2]+p[2]) && !strcmp(s[1]+p[1],s[3]+p[3]) ) now|=2;
		if ( !strcmp(s[0]+p[0],s[3]+p[3]) && !strcmp(s[1]+p[1],s[2]+p[2]) ) now|=4;
		ans&=now;
	}
	if ( ans==0 ) puts("NO");
	else if ( ans==1 ) puts("aabb");
	else if ( ans==2 ) puts("abab");
	else if ( ans==4 ) puts("abba");
	else if ( ans==7 ) puts("aaaa");
	else puts("OAQ");
	return 0;
}