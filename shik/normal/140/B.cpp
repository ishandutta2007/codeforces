// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,a[310][310],b[310],aa[310][310],bb[310],ans[310],sml[310];
int main()
{
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) for ( int j=1; j<=n; j++ ) scanf("%d",a[i]+j);
	for ( int i=1; i<=n; i++ ) scanf("%d",b+i);
	for ( int i=1; i<=n; i++ ) for ( int j=1; j<=n; j++ ) aa[i][a[i][j]]=j;
	for ( int i=1; i<=n; i++ ) bb[b[i]]=i;
	for ( int i=1; i<=n; i++ ) sml[i]=310;
	int b1=310,b2=310,w1=0,w2=0;
	for ( int i=1; i<=n; i++ ) {
		if ( bb[i]<b1 ) {
			b2=b1;
			w2=w1;
			b1=bb[i];
			w1=i;
		} else if ( bb[i]<b2 ) {
			b2=bb[i];
			w2=i;
		}
		for ( int j=1; j<=n; j++ ) {
			if ( w1==j ) {
				if ( w2!=0 && aa[j][w2]<sml[j] ) {
					sml[j]=aa[j][w2];
					ans[j]=i;
				}
			} else {
				if ( aa[j][w1]<sml[j] ) {
					sml[j]=aa[j][w1];
					ans[j]=i;
				}
			}
		}
	}
	for ( int i=1; i<=n; i++ ) printf("%d%c",ans[i],i==n?'\n':' ');
	return 0;
}