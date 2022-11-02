// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,a[110];
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) scanf("%d",a+i);
	sort(a,a+n);
	int ans=0,sum=0,t=0;
	for ( int i=0; i<n; i++ ) {
		if ( t+a[i]>710 ) break;
		t+=a[i];
		ans++;
		if ( t>350 ) sum+=t-350;
	}
	printf("%d %d\n",ans,sum);
	return 0;
}