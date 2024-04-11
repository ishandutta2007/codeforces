// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define N 510
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,m,t,tbl[N][N],star[N][N],sum[N];
int main()
{
	scanf("%d%d%d",&n,&m,&t);
	if ( t==0 ) {
		long long ans=0;
		for ( int i=1; i<=n; i++ ) for ( int j=1; j<=m; j++ ) ans+=i*j;
		cout<<ans<<endl;
		return 0;
	}
	for ( int i=1; i<=n; i++ ) for ( int j=1; j<=m; j++ ) scanf("%1d",tbl[i]+j);
	for ( int i=1; i<=n; i++ ) for ( int j=1; j<=m; j++ ) star[i][j]=(tbl[i][j]&&tbl[i-1][j]&&tbl[i+1][j]&&tbl[i][j-1]&&tbl[i][j+1]);
	long long ans=0;
	for ( int i=2; i<n; i++ ) {
		memset(sum,0,sizeof(sum));
		for ( int j=i; j<n; j++ ) {
			for ( int k=2; k<m; k++ ) sum[k]+=star[j][k];
			for ( int k=2,l=2,now=0; k<m; k++ ) {
				while ( l<m && (l<=k||now<t) ) now+=sum[l++];
				if ( now>=t ) ans+=m-l+1;
				now-=sum[k];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}