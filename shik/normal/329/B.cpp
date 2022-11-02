// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cctype>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 1010
int n,m,dis[N][N];
char s[N][N];
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
bool out( int x, int y ) { return x<0 || x>=n || y<0 || y>=m; }
void BFS( int x, int y ) {
    queue<int> q;
    dis[x][y]=0;
    q.push(x); q.push(y);
    while ( !q.empty() ) {
        x=q.front(); q.pop();
        y=q.front(); q.pop();
        for ( int i=0; i<4; i++ ) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if ( out(nx,ny) || s[nx][ny]=='T' || dis[nx][ny]!=-1 ) continue;
            dis[nx][ny]=dis[x][y]+1;
            q.push(nx); q.push(ny);
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for ( int i=0; i<n; i++ ) scanf("%s",s[i]);
    memset(dis,-1,sizeof(dis));
    int sx=-1,sy=-1;
    for ( int i=0; i<n; i++ ) for ( int j=0; j<m; j++ ) {
        if ( s[i][j]=='E' ) BFS(i,j);
        if ( s[i][j]=='S' ) sx=i,sy=j;
    }
    int ans=0;
    for ( int i=0; i<n; i++ ) for ( int j=0; j<m; j++ ) if ( isdigit(s[i][j]) && dis[i][j]!=-1 && dis[i][j]<=dis[sx][sy] ) ans+=s[i][j]-'0';
    printf("%d\n",ans);
    return 0;
}