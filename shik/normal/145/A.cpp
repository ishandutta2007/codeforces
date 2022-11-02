// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char sa[N],sb[N];
int main()
{
	scanf("%s %s",sa,sb);
	int c4=0,c7=0;
	for ( int i=0; sa[i]; i++ ) if ( sa[i]!=sb[i] ) {
		if ( sa[i]=='4' ) c4++;
		else c7++;
	}
	printf("%d\n",max(c4,c7));
	return 0;
}