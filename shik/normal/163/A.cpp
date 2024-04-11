// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 5010
#define MOD 1000000007
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char s[N],t[N];
int c[N];
int main()
{
	int n=strlen(gets(s));
	int m=strlen(gets(t));
	for ( int i=0; i<m; i++ ) for ( int j=n-1; j>=0; j-- ) if ( t[i]==s[j] ) c[j+1]=(c[j+1]+c[j]+1)%MOD;
	int ans=0;
	for ( int i=1; i<=n; i++ ) ans=(ans+c[i])%MOD;
	printf("%d\n",ans);
	return 0;
}