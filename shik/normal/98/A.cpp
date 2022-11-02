// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int a[3][4]={
	{1,2,3,4},
	{0,1,5,3},
	{0,2,5,4}};
set<string> sol;
void rot( string &s, int r[4] ) {
	for ( int i=1; i<4; i++ ) swap(s[r[i-1]],s[r[i]]);
}
string get( string s ) {
	string ret=s;
	for ( int i=0; i<4; i++ ) {
		for ( int j=0; j<4; j++ ) {
			for ( int k=0; k<4; k++ ) {
				ret=min(ret,s);
				rot(s,a[2]);
			}
			rot(s,a[1]);
		}
		rot(s,a[0]);
	}
	return ret;
}
int main()
{
	char s[10];
	gets(s);
	sort(s,s+6);
	do sol.insert(get(s)); while ( next_permutation(s,s+6) );
	printf("%d\n",SZ(sol));
	return 0;
}