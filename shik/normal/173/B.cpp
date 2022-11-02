// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define N 1010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int n,m,dis[4][N][N];
char s[N][N];
bool out( int x, int y ) { return x<0 || x>=n || y<0 || y>=m; }
int main()
{
	scanf("%d%d",&n,&m); m+=2;
	for ( int i=0; i<n; i++ ) scanf("%s",s[i]+1);
	memset(dis,-1,sizeof(dis));
	deque<int> q;
	q.push_back(1); q.push_back(0); q.push_back(0); dis[1][0][0]=0;
	while ( !q.empty() ) {
		int d=q.front(); q.pop_front();
		int x=q.front(); q.pop_front();
		int y=q.front(); q.pop_front();
		for ( int i=0; i<4; i++ ) {
			if ( (i^d)==2 ) continue;
			if ( i!=d && s[x][y]!='#' ) continue;
			int nx=x+dx[i],ny=y+dy[i];
			if ( out(nx,ny) || dis[i][nx][ny]!=-1 ) continue;
			if ( d==i ) {
				dis[i][nx][ny]=dis[d][x][y];
				q.push_front(ny); q.push_front(nx); q.push_front(i);
			} else {
				dis[i][nx][ny]=dis[d][x][y]+1;
				q.push_back(i); q.push_back(nx); q.push_back(ny);
			}
		}
	}
	printf("%d\n",dis[1][n-1][m-1]);
	return 0;
}