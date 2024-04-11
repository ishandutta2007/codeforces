// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char s[200][200],mx[200];
int main()
{
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	for ( int i=0; i<n; i++ ) scanf("%s",s[i]);
	for ( int i=0; i<n; i++ ) for ( int j=0; j<m; j++ ) mx[j]=max(mx[j],s[i][j]);
	for ( int i=0; i<n; i++ ) for ( int j=0; j<m; j++ ) if ( s[i][j]==mx[j] ) { ans++; break; }
	printf("%d\n",ans);
	return 0;
}