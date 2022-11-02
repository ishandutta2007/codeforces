// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 20010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,a[N],b[N],ans=-999999999;
int main()
{
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) scanf("%d",a+i);
	for ( int i=1; i<=n; i++ ) if ( n%i==0 && n/i>=3 ) {
		memset(b,0,sizeof(b));
		for ( int j=0; j<n; j++ ) b[j%i]+=a[j];
		ans=max(ans,*max_element(b,b+i));
	}
	printf("%d\n",ans);
	return 0;
}