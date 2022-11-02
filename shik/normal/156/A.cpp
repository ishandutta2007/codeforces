// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 2010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char s[N],t[N];
int main()
{
	int ns=strlen(gets(s));
	int nt=strlen(gets(t));
	int ans=nt;
	for ( int d=-N; d<=N; d++ ) {
		int now=nt;
		for ( int i=0; i<ns; i++ ) if ( i+d>=0 && i+d<nt && s[i]==t[i+d] ) now--;
		ans=min(ans,now);
	}
	printf("%d\n",ans);
	return 0;
}