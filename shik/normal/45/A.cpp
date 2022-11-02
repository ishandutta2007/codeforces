// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	char s[100],m[12][100]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	int n;
	scanf("%s %d",s,&n);
	for ( int i=0; i<12; i++ ) if ( strcmp(s,m[i])==0 ) printf("%s\n",m[(i+n)%12]);
	return 0;
}