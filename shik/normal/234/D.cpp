// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,d[110],b[110][110];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int m,k,fav[110]={};
	scanf("%d%d",&m,&k);
	for ( int i=0; i<k; i++ ) {
		int x;
		scanf("%d",&x);
		fav[x]=1;
	}
	char name[100][20];
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) {
		scanf("%s%d",name[i],d+i);
		for ( int j=0; j<d[i]; j++ ) scanf("%d",b[i]+j);
	}
	int sml[110],big[110];
	for ( int i=0; i<n; i++ ) {
		sml[i]=big[i]=0;
		for ( int j=0; j<d[i]; j++ ) if ( fav[b[i][j]] ) sml[i]++;
		int cz=0;
		for ( int j=0; j<d[i]; j++ ) if ( b[i][j]==0 ) cz++;
		big[i]=min(sml[i]+cz,k);
		sml[i]=0;
		bool vis[110]={};
		for ( int j=0; j<d[i]; j++ ) vis[b[i][j]]=1;
		for ( int j=0; j<d[i]; j++ ) {
			if ( b[i][j] ) {
				if ( fav[b[i][j]] ) sml[i]++;
				continue;
			}
			bool flg=0;
			for ( int l=1; l<=m; l++ ) if ( !vis[l] && !fav[l] ) {
				vis[l]=1;
				flg=1;
				break;
			}
			if ( flg ) continue;
			for ( int l=1; l<=m; l++ ) if ( !vis[l] ) { 
				vis[l]=1;
				if ( fav[l] ) sml[i]++;
				break;
			}
		}
	}
	for ( int i=0; i<n; i++ ) {
		int g1=0,g2=0;
		for ( int j=0; j<n; j++ ) if ( i!=j ) g1=max(g1,sml[j]);
		for ( int j=0; j<n; j++ ) if ( i!=j ) g2=max(g2,big[j]);
		if ( sml[i]>=g2 ) puts("0");
		else if ( big[i]<g1 ) puts("1");
		else puts("2");
	}
	return 0;
}