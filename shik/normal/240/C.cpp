// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	scanf("%d",&n);
	int m=__lg(n-1)+1;
	printf("%d\n",m);
	for ( int i=0; i<m; i++ ) {
		int l=(1<<i),c=0;
		for ( int j=0; j<n; j++ ) if ( j%(2*l)<l ) c++;
		printf("%d",c);
		for ( int j=0; j<n; j++ ) if ( j%(2*l)<l ) printf(" %d",j+1);
		puts("");
	}
	return 0;
}