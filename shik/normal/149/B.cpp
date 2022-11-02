// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int val( char c ) {
	if ( isdigit(c) ) return c-'0';
	return c-'A'+10;
}
int dec( char *s, int b ) {
	int r=0;
	for ( int i=0; s[i]; i++ ) r=r*b+val(s[i]);
	return r;
}
int main()
{
	char sa[10],sb[10];
	scanf("%[^:]:%s",sa,sb);
	vector<int> sol;
	int big=0;
	for ( int i=0; sa[i]; i++ ) big=max(big,val(sa[i]));
	for ( int i=0; sb[i]; i++ ) big=max(big,val(sb[i]));
	for ( int i=big+1; i<60; i++ ) if ( dec(sa,i)<24 && dec(sb,i)<60 ) sol.push_back(i);
	if ( dec(sa,60)<24 && dec(sb,60)<60 ) puts("-1");
	else if ( sol.empty() ) puts("0");
	else for ( int i=0; i<SZ(sol); i++ ) printf("%d%c",sol[i],i==SZ(sol)-1?'\n':' ');
	return 0;
}