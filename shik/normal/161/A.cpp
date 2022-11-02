// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef pair<int,int> PII;
PII a[N],b[N],c[N];
int main()
{
	int n,m,x,y;
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for ( int i=0; i<n; i++ ) scanf("%d",&a[i].first),a[i].second=i+1;
	for ( int i=0; i<m; i++ ) scanf("%d",&b[i].first),b[i].second=i+1;
	sort(a,a+n); sort(b,b+m);
	int ans=0;
	for ( int i=0,j=0; i<n; i++ ) {
		while ( j<m && b[j].first<a[i].first-x ) j++;
		if ( j<m && b[j].first<=a[i].first+y ) {
			c[ans++]=make_pair(a[i].second,b[j].second);
			j++;
		}
	}
	printf("%d\n",ans);
	for ( int i=0; i<ans; i++ ) printf("%d %d\n",c[i].first,c[i].second);
	return 0;
}