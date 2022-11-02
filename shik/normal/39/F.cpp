// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,m,k,a[110],b[110],ans=0,sol[110]={},sml=99999999;
	scanf("%d%d%d",&n,&m,&k);
	for ( int i=1; i<=m; i++ ) scanf("%d",a+i);
	for ( int i=1; i<=k; i++ ) scanf("%d",b+i);
	for ( int i=1; i<=m; i++ ) {
		int cnt=0;
		for ( int j=1; j<=k; j++ ) if ( b[j]%a[i]==0 ) cnt++;
		if ( cnt==sml ) sol[ans++]=i;
		else if ( cnt<sml ) {
			sml=cnt;
			ans=0;
			sol[ans++]=i;
		}
	}
	printf("%d\n",ans);
	for ( int i=0; i<ans; i++ ) printf("%d%c",sol[i],i==ans-1?'\n':' ');
	return 0;
}