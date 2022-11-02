// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 30010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char s[N][25];
int main()
{
	int n;
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) scanf("%s",s[i]);
	int ans=strlen(s[0]);
	for ( int i=1; i<n; i++ ) while ( strncmp(s[0],s[i],ans)!=0 ) ans--;
	printf("%d\n",ans);
	return 0;
}