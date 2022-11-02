// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<char> > tbl;
vector<int> x,y;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	x.resize(n);
	y.resize(m);
	tbl.resize(n);
	for ( int i=0; i<n; i++ ) tbl[i].resize(m);
	for ( int i=0; i<n; i++ ) 
		for ( int j=0; j<m; j++ )
			scanf(" %c",&tbl[i][j]);
	for ( int i=0; i<n; i++ )
		for ( int j=0; j<m; j++ ) {
			if ( tbl[i][j]=='.' ) continue;
			if ( tbl[i][j]=='1' || tbl[i][j]=='2' ) x[i]|=1+(j&1);
			if ( tbl[i][j]=='3' || tbl[i][j]=='4' ) x[i]|=2-(j&1);
			if ( tbl[i][j]=='1' || tbl[i][j]=='4' ) y[j]|=1+(i&1);
			if ( tbl[i][j]=='2' || tbl[i][j]=='3' ) y[j]|=2-(i&1);
		}
	int ans=1,MOD=1000003;
	for ( int i=0; i<n; i++ )
		if ( x[i]==0 ) ans=ans*2%MOD;
		else if ( x[i]==3 ) ans=0;
	for ( int i=0; i<m; i++ )
		if ( y[i]==0 ) ans=ans*2%MOD;
		else if ( y[i]==3 ) ans=0;
	printf("%d\n",ans);
	return 0;
}