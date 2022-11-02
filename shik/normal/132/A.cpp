// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int rev( int n ) {
	int m=0;
	for ( int i=0; i<8; i++ ) {
		m=m*2+(n&1);
		n>>=1;
	}
	return m;
}
int main()
{
	char s[110]; gets(s);
	for ( int i=0; s[i]; i++ ) printf("%d\n",(256-rev(s[i])+(i==0?0:rev(s[i-1])))%256); // s[i]=rev(t[i]-rev(s[i-1]))
	return 0;
}