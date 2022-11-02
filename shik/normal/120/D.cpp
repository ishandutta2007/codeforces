// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m,s[3],w[60][60],sx[60]={},sy[60]={};
	scanf("%d%d",&n,&m);
	for ( int i=1; i<=n; i++ ) for ( int j=1; j<=m; j++ ) scanf("%d",w[i]+j);
	for ( int i=0; i<3; i++ ) scanf("%d",s+i); sort(s,s+3);
	for ( int i=1; i<=n; i++ ) {
		sx[i]=sx[i-1];
		for ( int j=1; j<=m; j++ ) sx[i]+=w[i][j];
	}
	for ( int i=1; i<=m; i++ ) {
		sy[i]=sy[i-1];
		for ( int j=1; j<=n; j++ ) sy[i]+=w[j][i];
	}
	int ans=0;
	for ( int i=1; i<n; i++ )
		for ( int j=i+1; j<n; j++ ) {
			int t[3];
			t[0]=sx[i];
			t[1]=sx[j]-sx[i];
			t[2]=sx[n]-sx[j];
			sort(t,t+3);
			if ( t[0]==s[0] && t[1]==s[1] && t[2]==s[2] ) ans++;
		}
	for ( int i=1; i<m; i++ )
		for ( int j=i+1; j<m; j++ ) {
			int t[3];
			t[0]=sy[i];
			t[1]=sy[j]-sy[i];
			t[2]=sy[m]-sy[j];
			sort(t,t+3);
			if ( t[0]==s[0] && t[1]==s[1] && t[2]==s[2] ) ans++;
		}
	printf("%d\n",ans);
	return 0;
}