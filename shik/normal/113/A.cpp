// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#define N 100010
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
string tbl[6]={"lios","liala","etr","etra","initis","inites"};
int valid( string s ) {
	for ( ; !s.empty(); s=s.substr(1) ) for ( int i=0; i<6; i++ ) if ( s==tbl[i] ) return i/2+1;
	return 0;
}
int gender( string s ) {
	for ( ; !s.empty(); s=s.substr(1) ) for ( int i=0; i<6; i++ ) if ( s==tbl[i] ) return i%2;
	return 2;
}
string s[N];
int main()
{
	int n=0;
	while ( cin>>s[n] ) n++;
	if ( n==1 ) puts(valid(s[0])?"YES":"NO");
	else {
		for ( int i=0; i<n; i++ ) if ( gender(s[i])!=gender(s[0]) ) { puts("NO"); return 0; }
		int w=0;
		while ( w<n && valid(s[w])!=2 ) w++;
		if ( w==n ) { puts("NO"); return 0; }
		for ( int i=0; i<w; i++ ) if ( valid(s[i])!=1 ) { puts("NO"); return 0; }
		for ( int i=w+1; i<n; i++ ) if ( valid(s[i])!=3 ) { puts("NO"); return 0; }
		puts("YES");
	}
	return 0;
}