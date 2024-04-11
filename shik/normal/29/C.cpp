// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
map<int,vector<int> > e;
map<int,bool> vis;
int main()
{
	int n,a,b;
	scanf("%d",&n);
	while ( n-- ) {
		scanf("%d%d",&a,&b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	int p=0;
	FOR(it,e) if ( SZ(it->second)==1 ) p=it->first;
	do {
		vis[p]=1;
		printf("%d ",p);
		if ( vis[e[p][0]] ) p=e[p][1];
		else p=e[p][0];
	} while ( SZ(e[p])>1 );
	printf("%d\n",p);
	return 0;
}