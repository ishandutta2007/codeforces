// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
inline void chkmin( int &a, int b ) { if ( b<a ) a=b; }
inline int bit( int x, int i ) { return (x>>i)&1; }
int n,a[N],nx[N][20],ans;
bool vis[1<<20];
inline void chk( int x ) {
	if ( vis[x] ) return;
	vis[x]=1;
	ans++;
}
int main()
{
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) scanf("%d",a+i);
	for ( int i=0; i<20; i++ ) nx[n][i]=n;
	for ( int i=n-1; i>=0; i-- ) {
		for ( int j=0; j<20; j++ ) nx[i][j]=nx[i+1][j];
		for ( int j=0; j<20; j++ ) if ( bit(a[i],j) ) nx[i][j]=i;
	}
	for ( int i=0; i<n; i++ ) {
		int s=a[i],p=i;
		while ( 1 ) {
			chk(s);
			int q=n;
			for ( int j=0; j<20; j++ ) if ( !bit(s,j) ) chkmin(q,nx[p][j]);
			if ( q==n ) break;
			p=q;
			s|=a[p];
		}
	}
	printf("%d\n",ans);
	return 0;
}