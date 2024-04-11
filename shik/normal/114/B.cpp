// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
#define N 16
using namespace std;
map<string,int> tbl;
int n,e[N][N];
inline int bit( int x, int i ) { return (x>>i)&1; }
bool chk( int s ) {
	for ( int j=0; j<n; j++ ) if ( bit(s,j) )
		for ( int k=j+1; k<n; k++ ) if ( bit(s,k) )
			if ( e[j][k] ) return 0;
	return 1;
}
int main()
{
	int m,x,y;
	char a[100],b[100],name[100][100];
	scanf("%d%d",&n,&m);
	for ( int i=0; i<n; i++ ) {
		scanf("%s",name[i]);
		tbl[name[i]]=i;
	}
	while ( m-- ) {
		scanf("%s %s",a,b);
		x=tbl[a];
		y=tbl[b];
		e[x][y]=e[y][x]=1;
	}
	int ans=0,sol=0;
	for ( int i=0; i<(1<<n); i++ ) {
		int cnt=__builtin_popcount(i);
		if ( cnt<=ans || !chk(i) ) continue;
		ans=cnt;
		sol=i;
	}
	vector<string> v;
	for ( int i=0; i<n; i++ )
		if ( bit(sol,i) ) v.push_back(name[i]);
	sort(v.begin(),v.end());
	printf("%d\n",ans);
	FOR(it,v) printf("%s\n",it->c_str());
	return 0;
}