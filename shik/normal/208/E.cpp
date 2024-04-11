// by shik
#include <cstdio>
#include <algorithm>
#include <vector>
#define N 100010
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int f[17][N],d[N],l[N],r[N],t;
vector<int> e[N],c[N];
void go( int p, int lv ) {
	d[p]=lv;
	c[lv].push_back(t);
	l[p]=t++;
	FOR(it,e[p]) go(*it,lv+1);
	r[p]=t;
}
int main()
{
	int n,m,v,p;
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) scanf("%d",f[0]+i);
	for ( int i=1; i<=n; i++ ) e[f[0][i]].push_back(i);
	go(0,0);
	for ( int i=1; i<17; i++ ) for ( int j=1; j<=n; j++ ) f[i][j]=f[i-1][f[i-1][j]];
	scanf("%d",&m);
	while ( m-- ) {
		scanf("%d%d",&v,&p);
		vector<int> &u=c[d[v]];
		for ( int i=16; i>=0; i-- ) if ( (p>>i)&1 ) v=f[i][v];
		printf("%ld%c",v==0?0:lower_bound(u.begin(),u.end(),r[v])-lower_bound(u.begin(),u.end(),l[v])-1,m?' ':'\n');
	}
	return 0;
}