// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
using namespace std;
int num[N],cnt[N],tmt[N];
int main()
{
	int n;
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) scanf("%d",num+i);
	for ( int i=0; i<n; i++ ) cnt[num[i]]++;
	for ( int i=2; i<N; i++ )
		if ( cnt[i]>cnt[i-1] ) {
			puts("-1");
			return 0;
		}
	printf("%d\n",cnt[1]);
	for ( int i=0; i<n; i++ ) printf("%d%c",++tmt[num[i]],i==n-1?'\n':' ');
	return 0;
}