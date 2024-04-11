// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,k,s[8][8],l[8]={0,1,2,3,4,5,6,7},ans=1000000000;
	scanf("%d%d",&n,&k);
	for ( int i=0; i<n; i++ ) for ( int j=0; j<k; j++ ) scanf("%1d",s[i]+j);
	do {
		int sml=1000000000,big=0;
		for ( int i=0; i<n; i++ ) {
			int x=0;
			for ( int j=0; j<k; j++ ) x=x*10+s[i][l[j]];
			big=max(x,big);
			sml=min(x,sml);
		}
		ans=min(ans,big-sml);
	} while ( next_permutation(l,l+k) );
	printf("%d\n",ans);
	return 0;
}