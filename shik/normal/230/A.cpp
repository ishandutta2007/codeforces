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
	int s,n;
	PII a[1010];
	scanf("%d%d",&s,&n);
	for ( int i=0; i<n; i++ ) scanf("%d%d",&a[i].first,&a[i].second);
	sort(a,a+n);
	for ( int i=0; i<n; i++ ) {
		if ( s<=a[i].first ) return puts("NO"),0;
		s+=a[i].second;
	}
	puts("YES");
	return 0;
}