// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1000010
using namespace std;
char s[N];
int go( int n ) {
	if ( n<10 ) return 1;
	int sum=0;
	while ( n ) {
		sum+=n%10;
		n/=10;
	}
	return go(sum)+1;
}
int main()
{
	gets(s);
	if ( strlen(s)==1 ) puts("0");
	else {
		int sum=0;
		for ( int i=0; s[i]; i++ ) sum+=s[i]-'0';
		printf("%d\n",go(sum));
	}
	return 0;
}