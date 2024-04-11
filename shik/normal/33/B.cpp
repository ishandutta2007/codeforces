// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define L 100010
#define S 130
#define INF 514514514
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char s[L],t[L],z[L];
int w[S][S];
int main()
{
	memset(w,-1,sizeof(w));
	for ( int i=0; i<S; i++ ) w[i][i]=0;
	int m,c; char a,b;
	scanf("%s %s %d",s,t,&m);
	if ( strlen(s)!=strlen(t) ) { puts("-1"); return 0; }
	while ( m-- ) {
		scanf(" %c %c %d",&a,&b,&c);
		if ( w[a][b]==-1 || c<w[a][b] ) w[a][b]=c;
	}
	for ( int k=0; k<S; k++ )
		for ( int i=0; i<S; i++ )
			for ( int j=0; j<S; j++ )
				if ( w[i][k]!=-1 && w[k][j]!=-1 && (w[i][j]==-1||w[i][k]+w[k][j]<w[i][j]) ) w[i][j]=w[i][k]+w[k][j];
	int ans=0;
	for ( int i=0; s[i]; i++ ) {
		int sml=INF;
		for ( int j=0; j<S; j++ ) if ( w[s[i]][j]!=-1 && w[t[i]][j]!=-1 && w[s[i]][j]+w[t[i]][j]<sml ) sml=w[s[i]][j]+w[t[i]][j],z[i]=j;
		if ( sml==INF ) { puts("-1"); return 0; }
		ans+=sml;
	}
	printf("%d\n%s\n",ans,z);
	return 0;
}