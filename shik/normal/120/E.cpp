// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,n;
	scanf("%d",&t);
	while ( t-- ) {
		scanf("%d",&n);
		printf("%d\n",1-n%2);
	}
	return 0;
}