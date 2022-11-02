// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 200
using namespace std;
char tbl[N][N];
int lf[N],rt[N];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for ( int i=1; i<=n; i++ ) scanf("%s",tbl[i]+1);
	for ( int i=1; i<=n; i++ ) lf[i]=m+1,rt[i]=0;
	for ( int i=1; i<=n; i++ )
		for ( int j=1; j<=m; j++ )
			if ( tbl[i][j]=='W' ) {
				lf[i]=min(lf[i],j);
				rt[i]=max(rt[i],j);
			}
	int ans=0,pos=1;
	for ( int i=1; i<=n; i++ ) {
		if ( i&1 ) {
			while ( pos>lf[i] ) pos--,ans++;
			if ( i>1 ) ans++;
			while ( pos<rt[i] ) pos++,ans++;
		} else {
			while ( pos<rt[i] ) pos++,ans++;
			if ( i>1 ) ans++;
			while ( pos>lf[i] ) pos--,ans++;
		}
	}
	for ( int i=n; i>1; i-- )
		if ( rt[i]==0 ) ans--;
		else break;
	printf("%d\n",ans);
	return 0;
}