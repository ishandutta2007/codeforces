// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
char tbl[12][20]={"C","C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"};
int get( const char *s ) {
	for ( int i=0; i<12; i++ )
		if ( strcmp(s,tbl[i])==0 ) return i;
	puts("QQ");
	return -1;
}
int dis( const char *a, const char *b ) {
	int d=get(b)-get(a);
	if ( d<0 ) d+=12;
	return d;
}
string s[3];
bool major() {
	return dis(s[0].c_str(),s[1].c_str())==4 && dis(s[1].c_str(),s[2].c_str())==3;
}
bool minor() {
	return dis(s[0].c_str(),s[1].c_str())==3 && dis(s[1].c_str(),s[2].c_str())==4;
}
int main()
{
	cin>>s[0]>>s[1]>>s[2];
	sort(s,s+3);
	do {
		if ( major() ) { puts("major"); return 0; }
		if ( minor() ) { puts("minor"); return 0; }
	} while ( next_permutation(s,s+3) );
	puts("strange");
	return 0;
}