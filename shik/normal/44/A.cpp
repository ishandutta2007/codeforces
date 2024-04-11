// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <string>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n;
	char a[20],b[20];
	set<pair<string,string> > tmt;
	scanf("%d",&n);
	while ( n-- ) {
		scanf("%s %s",a,b);
		tmt.insert(make_pair(a,b));
	}
	printf("%d\n",(int)tmt.size());
	return 0;
}