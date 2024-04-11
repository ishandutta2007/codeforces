// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 50
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char tbl[N][N];
int ok[130];
int main()
{
	int n,m,d,q,c;
	scanf("%d%d%d",&n,&m,&d);
	for ( int i=0; i<n; i++ ) scanf("%s",tbl[i]);
	for ( int i=0; i<n; i++ ) for ( int j=0; j<m; j++ ) if ( tbl[i][j]!='S' ) {
		ok[(int)tbl[i][j]]=1;
		for ( int k=0; k<n; k++ ) for ( int l=0; l<m; l++ ) if ( tbl[k][l]=='S' && abs(i-k)*abs(i-k)+abs(j-l)*abs(j-l)<=d*d ) ok[tbl[i][j]+'A'-'a']=1;
	}
	bool flg=0;
	for ( int i=0; i<n; i++ ) for ( int j=0; j<m; j++ ) if ( tbl[i][j]=='S' ) flg=1;
	if ( flg ) for ( int i='a'; i<='z'; i++ ) if ( ok[i] && !ok[i+'A'-'a'] ) ok[i+'A'-'a']=2;
	scanf("%d ",&q);
	int ans=0;
	while ( q-- ) {
		c=getchar();
		if ( !ok[c] ) { puts("-1"); return 0; }
		if ( ok[c]==2 ) ans++;
	}
	printf("%d\n",ans);
	return 0;
}