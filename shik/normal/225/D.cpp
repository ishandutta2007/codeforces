// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define N 15
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int n,m,gx,gy,len,vis[N][N],ucs;
inline bool out( int x, int y ) { return x<0 || x>=n || y<0 || y>=m; }
char s[N][N+1];
struct P {
    int x[9],y[9],step,h;
    P() { step=0; }
    void cal_h() { h=step+abs(gx-x[0])+abs(gy-y[0]); }
    int get_hsh() {
        int hsh=0;
        for ( int i=0; i<len; i++ ) hsh=hsh*131+x[i]+1;
        for ( int i=0; i<len; i++ ) hsh=hsh*131+y[i]+1;
        return hsh;
    }
    bool operator <( const P &p ) const { return h>p.h; }
};
int vc[N][N];
bool chk( int x, int y ) {
    vc[x][y]=1;
    if ( s[x][y]=='@' ) return 1;
    for ( int i=0; i<4; i++ ) {
        int nx=x+dx[i],ny=y+dy[i];
        if ( out(nx,ny) || vc[nx][ny] || s[nx][ny]=='#' ) continue;
        if ( chk(nx,ny) ) return 1;
    }
    return 0;
}
int main()
{
    scanf("%d%d",&n,&m);
    for ( int i=0; i<n; i++ ) scanf("%s",s[i]);
    for ( int i=0; i<n; i++ ) for ( int j=0; j<m; j++ ) if ( s[i][j]=='@' ) gx=i,gy=j;
    P p,np;
    for ( int i=1; i<=9; i++ ) for ( int j=0; j<n; j++ ) for ( int k=0; k<m; k++ ) if ( s[j][k]=='0'+i ) {
        p.x[len]=j;
        p.y[len]=k;
        len++;
    }
    if ( !chk(p.x[0],p.y[0]) ) return puts("-1"),0;
    set<int> vs;
    priority_queue<P> q;
    p.cal_h(); q.push(p); vs.insert(p.get_hsh());
    while ( !q.empty() ) {
        p=q.top(); q.pop();
        ucs++;
        for ( int i=0; i<len-1; i++ ) vis[p.x[i]][p.y[i]]=ucs;
        for ( int i=0; i<4; i++ ) {
            int hx=p.x[0]+dx[i],hy=p.y[0]+dy[i];
            if ( out(hx,hy) ) continue;
            if ( vis[hx][hy]==ucs ) continue;
            if ( s[hx][hy]=='#' ) continue;
            if ( s[hx][hy]=='@' ) return printf("%d\n",p.step+1),0;
            np.x[0]=hx; np.y[0]=hy; np.step=p.step+1;
            memcpy(np.x+1,p.x,(len-1)*sizeof(int));
            memcpy(np.y+1,p.y,(len-1)*sizeof(int));
            if ( vs.count(np.get_hsh()) ) continue;
            vs.insert(np.get_hsh());
            np.cal_h(); q.push(np);
        }
    }
    puts("-1");
    return 0;
}