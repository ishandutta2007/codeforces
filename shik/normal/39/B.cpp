// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,p=1,x;
	vector<int> sol;
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) {
		scanf("%d",&x);
		if ( x==p ) sol.push_back(i+2000),p++;
	}
	printf("%d\n",(int)sol.size());
	for ( int i=0; i<(int)sol.size(); i++ ) printf("%d%c",sol[i],i==(int)sol.size()-1?'\n':' ');
	return 0;
}