// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 1800
int n,m,img[N][N];
void input() {
    scanf("%d%d",&n,&m);
    for ( int i=1; i<=n; i++ ) for ( int j=1; j<=m; j++ ) scanf("%d",img[i]+j);
}
int nc,cc[N][N];
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
void BFS( int x, int y, int c ) {
    queue<int> q;
    cc[x][y]=c;
    q.push(x);
    q.push(y);
    while ( !q.empty() ) {
        x=q.front(); q.pop();
        y=q.front(); q.pop();
        for ( int i=0; i<4; i++ ) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if ( img[nx][ny] && !cc[nx][ny] ) {
                cc[nx][ny]=c;
                q.push(nx);
                q.push(ny);
            }
        }
    }
}
int sum[N][N],bye[N][N];
void build() {
    for ( int i=1; i<=n; i++ ) for ( int j=1; j<=m; j++ ) if ( img[i][j] && !cc[i][j] ) BFS(i,j,++nc);
    for ( int i=1; i<=n; i++ ) for ( int j=1; j<=m; j++ ) sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+img[i][j];
    for ( int i=1; i<=n-5; i++ ) for ( int j=1; j<=m-5; j++ ) {
        int now=sum[i+5][j+5]-sum[i+5][j-1]-sum[i-1][j+5]+sum[i-1][j-1];
        if ( now==36 ) {
            bye[i][j]++;
            bye[i+6][j]--;
            bye[i][j+6]--;
            bye[i+6][j+6]++;
        }
    }
    for ( int i=1; i<=n; i++ ) for ( int j=1; j<=m; j++ ) bye[i][j]+=bye[i-1][j]+bye[i][j-1]-bye[i-1][j-1];
    for ( int i=1; i<=n; i++ ) for ( int j=1; j<=m; j++ ) if ( bye[i][j] ) cc[i][j]=0;
    //for ( int i=1; i<=n; i++,puts("") ) for ( int j=1; j<=m; j++ ) printf("%d",cc[i][j]);
}
int BFS2( int x, int y ) {
    queue<int> q;
    cc[x][y]=0;
    q.push(x);
    q.push(y);
    int cnt=0;
    while ( !q.empty() ) {
        cnt++;
        x=q.front(); q.pop();
        y=q.front(); q.pop();
        for ( int i=0; i<4; i++ ) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if ( cc[nx][ny] ) {
                cc[nx][ny]=0;
                q.push(nx);
                q.push(ny);
            }
        }
    }
    return cnt;
}
int cnt[N*N];
void solve() {
    for ( int i=1; i<=n; i++ ) for ( int j=1; j<=m; j++ ) if ( cc[i][j] ) {
        int c=cc[i][j];
        int now=BFS2(i,j);
        if ( now>10 ) cnt[c]++;
    }
    sort(cnt+1,cnt+nc+1);
    printf("%d\n",nc);
    for ( int i=1; i<=nc; i++ ) printf("%d%c",cnt[i],i==nc?'\n':' ');
}
int main()
{
    input();
    build();
    solve();
    return 0;
}