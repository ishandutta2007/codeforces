// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
set<char> s;
int main()
{
	int n,m; char c,tbl[110][110];
	scanf("%d%d %c",&n,&m,&c);
	for ( int i=0; i<n; i++ ) scanf("%s",tbl[i]);
	for ( int i=0; i<n; i++ )
		for ( int j=0; j<m; j++ )
			if ( tbl[i][j]==c )
				for ( int dx=-1; dx<=1; dx++ )
					for ( int dy=-1; dy<=1; dy++ ) {
						if ( dx&&dy ) continue;
						int x=i+dx;
						int y=j+dy;
						if ( x<0 || y<0 || x>=n || y>=m ) continue;
						if ( tbl[x][y]!=c && tbl[x][y]!='.' ) s.insert(tbl[x][y]);
					}
	printf("%d\n",(int)s.size());
	return 0;
}