// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#define N 210
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	map<int,set<int> > sx,sy;
	int n,x[N],y[N],ans=0;
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) scanf("%d%d",x+i,y+i);
	for ( int i=0; i<n; i++ ) sx[x[i]].insert(y[i]);
	for ( int i=0; i<n; i++ ) sy[y[i]].insert(x[i]);
	for ( int i=0; i<n; i++ ) if ( y[i]!=*sx[x[i]].begin() && y[i]!=*sx[x[i]].rbegin() && x[i]!=*sy[y[i]].begin() && x[i]!=*sy[y[i]].rbegin() ) ans++;
	printf("%d\n",ans);
	return 0;
}