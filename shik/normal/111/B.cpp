// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <unordered_set>
#define N 100010
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n;
struct BIT {
	unordered_set<int> dat[N];
	void ins( int x, int v ) {
		for ( int i=x; i<=n; i+=i&-i )
			if ( dat[i].count(v) ) return;
			else dat[i].insert(v);
	}
	bool Q( int x, int v ) {
		for ( int i=x; i; i-=i&-i )
			if ( dat[i].count(v) ) return 1;
		return 0;
	}
} bit;
int main()
{
	int x,y,ans;
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) {
		scanf("%d%d",&x,&y);
		ans=0;
		for ( int j=1; j*j<=x; j++ ) {
			if ( x%j ) continue;
			if ( !bit.Q(n-i+1+y,j) ) ans++;
			bit.ins(n-i+1,j);
			if ( j*j==x ) continue;
			if ( !bit.Q(n-i+1+y,x/j) ) ans++;
			bit.ins(n-i+1,x/j);
		}
		printf("%d\n",ans);
	}
	return 0;
}