// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef pair<int,int> PII;
int main()
{
	int n,m,s=0,c[1010];
	PII a[50];
	scanf("%d%d",&n,&m);
	for ( int i=0; i<m; i++ ) scanf("%d",&a[i].first),a[i].second=i+1;
	for ( int i=0; i<m; i++ ) a[i].first=min(a[i].first,n/2);
	sort(a,a+m);
	for ( int i=0; i<m; i++ ) s+=a[i].first;
	if ( s<n ) return puts("-1"),0;
	int p=m-1;
	for ( int i=0; i<n; i+=2 ) {
		c[i]=a[p].second;
		if ( --a[p].first==0 ) p--;
	}
	for ( int i=1; i<n; i+=2 ) {
		c[i]=a[p].second;
		if ( --a[p].first==0 ) p--;
	}
	for ( int i=0; i<n; i++ ) printf("%d%c",c[i],i==n-1?'\n':' ');
	return 0;
}