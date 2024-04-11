// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 200010
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
pair<int,int> a[N];
int main()
{
	int n,big=0,ans=0;
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) scanf("%d%d",&a[i].first,&a[i].second);
	sort(a,a+n);
	for ( int i=0; i<n; i++ ) {
		if ( big>a[i].second ) ans++;
		else big=a[i].second;
	}
	printf("%d\n",ans);
	return 0;
}