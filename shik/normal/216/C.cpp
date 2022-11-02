// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 5140
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	vector<int> sol;
	int n,m,k,o[N]={},now=0;
	scanf("%d%d%d",&n,&m,&k);
	for ( int i=1; i<=n+m; i++ ) {
		while ( now<k ) {
			sol.push_back(i);
			now++; o[i+n-1]++;
		}
		now-=o[i];
		if ( now==0 ) {
			sol.push_back(i);
			now++; o[i+n-1]++;
		}
	}
	printf("%d\n",SZ(sol));
	for ( int i=0; i<SZ(sol); i++ ) printf("%d%c",sol[i],i==SZ(sol)-1?'\n':' ');
	return 0;
}