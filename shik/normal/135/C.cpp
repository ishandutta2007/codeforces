// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,c0,c1,c2;
char s[N];
bool chk_00() {
	if ( n%2==0 ) {
		if ( c0+c2>=c1+2 ) return 1;
		else return 0;
	} else {
		if ( c0+c2>=c1+1 ) return 1;
		else return 0;
	}
}
bool chk_01() {
	if ( s[n-1]=='0' ) return 0;
	if ( s[n-1]=='?' ) c2--,c1++;
	if ( n%2==0 ) {
		if ( c0+c2>=c1 && c1+c2>=c0 ) return 1;
		else return 0;
	} else {
		if ( c0+c2>=c1-1 && c1+c2>=c0+1 ) return 1;
		else return 0;
	}
}
bool chk_10() {
	if ( s[n-1]=='1' ) return 0;
	if ( s[n-1]=='?' ) c2--,c0++;
	if ( n%2==0 ) {
		if ( c0+c2>=c1 && c1+c2>=c0 ) return 1;
		else return 0;
	} else {
		if ( c0+c2>=c1-1 && c1+c2>=c0+1 ) return 1;
		else return 0;
	}
}
bool chk_11() {
	if ( n%2==0 ) {
		if ( c1+c2>=c0+2 ) return 1;
		else return 0;
	} else {
		if ( c1+c2>=c0+3 ) return 1;
		else return 0;
	}
}
int main()
{
	n=strlen(gets(s));
	for ( int i=c0=c1=c2=0; i<n; i++ ) {
		if ( s[i]=='0' ) c0++;
		else if ( s[i]=='1' ) c1++;
		else c2++;
	}
	if ( chk_00() ) puts("00");
	for ( int i=c0=c1=c2=0; i<n; i++ ) {
		if ( s[i]=='0' ) c0++;
		else if ( s[i]=='1' ) c1++;
		else c2++;
	}
	if ( chk_01() ) puts("01");
	for ( int i=c0=c1=c2=0; i<n; i++ ) {
		if ( s[i]=='0' ) c0++;
		else if ( s[i]=='1' ) c1++;
		else c2++;
	}
	if ( chk_10() ) puts("10");
	for ( int i=c0=c1=c2=0; i<n; i++ ) {
		if ( s[i]=='0' ) c0++;
		else if ( s[i]=='1' ) c1++;
		else c2++;
	}
	if ( chk_11() ) puts("11");
	return 0;
}