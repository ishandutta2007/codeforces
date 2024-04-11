// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char s[2][N];
queue<int> q;
int dis[2][N];
bool relax( int a, int &b ) {
	if ( b==-1 || a<b ) {
		b=a;
		return 1;
	}
	return 0;
}
int main()
{
	int n,k;
	scanf("%d%d%s%s",&n,&k,s[0],s[1]);
	memset(dis,-1,sizeof(dis));
	q.push(0); q.push(0); dis[0][0]=0;
	while ( !q.empty() ) {
		int x=q.front(); q.pop();
		int y=q.front(); q.pop();
		if ( y<dis[x][y] ) continue;
		if ( y+k>=n ) {
			puts("YES");
			return 0;
		}
		if ( y>0 && s[x][y-1]!='X' && relax(dis[x][y]+1,dis[x][y-1]) ) { q.push(x); q.push(y-1); }
		if ( s[x][y+1]!='X' && relax(dis[x][y]+1,dis[x][y+1]) ) { q.push(x); q.push(y+1); }
		if ( s[x^1][y+k]!='X' && relax(dis[x][y]+1,dis[x^1][y+k]) ) { q.push(x^1); q.push(y+k); }
	}
	puts("NO");
	return 0;
}