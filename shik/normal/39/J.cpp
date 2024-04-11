// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1000010
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
char a[N],b[N];
using namespace std;
int main()
{
	scanf("%s%s",a,b);
	int n=strlen(a);
	int L=0,R=n-1;
	while ( a[L]==b[L] ) L++;
	while ( R>0 && a[R]==b[R-1] ) R--;
	if ( L<R ) puts("0");
	else {
		printf("%d\n",L-R+1);
		for ( int i=R; i<=L; i++ ) printf("%d%c",i+1,i==L?'\n':' ');
	}
	return 0;
}