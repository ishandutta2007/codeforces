// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#define N 100010
#define MP make_pair
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
vector<int> e[N];
set<pair<int,int> > t1,t2;
int v1[N],v2[N];
void go1( int p ) {
	v1[p]=1;
	FOR(it,e[p]) if ( !v1[*it] ) {
		t1.insert(MP(p,*it));
		go1(*it);
	}
}
void go2( int p ) {
	v2[p]=1;
	FOR(it,e[p]) if ( !t1.count(MP(p,*it)) && !t2.count(MP(*it,p)) ) {
		t2.insert(MP(p,*it));
		if ( !v2[*it] ) go2(*it);
	}
}
int main()
{
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	for ( int i=0; i<m; i++ ) {
		scanf("%d%d",&a,&b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	go1(1); go2(1);
	if ( count(v2+1,v2+n+1,1)!=n ) return puts("0"),0;
	for ( int i=1; i<=n; i++ ) FOR(it,e[i]) if ( t1.count(MP(i,*it)) || t2.count(MP(*it,i)) ) printf("%d %d\n",i,*it);
	return 0;
}