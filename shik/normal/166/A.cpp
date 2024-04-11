// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
pair<int,int> s[55];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for ( int i=0; i<n; i++ ) {
		scanf("%d%d",&s[i].first,&s[i].second);
		s[i].first*=-1;
	}
	sort(s,s+n);
	printf("%d\n",count(s,s+n,s[k-1]));
	return 0;
}