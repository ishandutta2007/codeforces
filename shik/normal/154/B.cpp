// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
vector<int> fac[N];
set<int> pri[N];
int hav[N];
bool check( int x ) {
	FOR(it,fac[x]) if ( !pri[*it].empty() ) {
		printf("Conflict with %d\n",*pri[*it].begin());
		return 0;
	}
	return 1;
}
int main()
{
	int n,m,x; char op;
	scanf("%d%d",&n,&m);
	for ( int i=2; i<=n; i++ ) if ( fac[i].empty() ) for ( int j=i; j<=n; j+=i ) fac[j].push_back(i);
	while ( m-- ) {
		scanf(" %c %d",&op,&x);
		if ( op=='+' ) {
			if ( hav[x] ) puts("Already on");
			else if ( check(x) ) {
				hav[x]=1;
				FOR(it,fac[x]) pri[*it].insert(x);
				puts("Success");
			}
		} else if ( op=='-' ) {
			if ( !hav[x] ) puts("Already off");
			else {
				hav[x]=0;
				FOR(it,fac[x]) pri[*it].erase(x);
				puts("Success");
			}
		} else puts("QQ");
	}
	return 0;
}