// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int get( int n ) {
	char s[20];
	sprintf(s,"%d",n);
	int r=0;
	for ( int i=0; s[i]; i++ ) if ( s[i]=='4' || s[i]=='7' ) r=r*10+s[i]-'0';
	return r;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b); a++;
	while ( get(a)!=b ) a++;
	printf("%d\n",a);
	return 0;
}