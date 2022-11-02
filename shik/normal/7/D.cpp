// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 5000010
#define H 131
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char s[N];
int pw[N]={1},h1[N],h2[N],dp[N];
int main()
{
	int n=strlen(gets(s+1));
	for ( int i=1; i<=n; i++ ) pw[i]=pw[i-1]*H;
	for ( int i=1; i<=n; i++ ) h1[i]=h1[i-1]*H+s[i];
	for ( int i=1; i<=n; i++ ) h2[i]=h2[i-1]+s[i]*pw[i-1];
	for ( int i=1; i<=n; i++ ) if ( h1[i]==h2[i] ) dp[i]=dp[i/2]+1;
	int ans=0;
	for ( int i=1; i<=n; i++ ) ans+=dp[i];
	printf("%d\n",ans);
	return 0;
}