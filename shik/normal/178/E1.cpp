// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#define N 2010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
double sqr( double x ) { return x*x; }
const int dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};
//const int dx[]={1,0,-1,0,1,0,-1,0},dy[]={0,1,0,-1,0,1,0,-1};
struct P {
    int x,y;
    P(){}
    P( int _x, int _y ):x(_x),y(_y){}
} p[N*N];
int n,g[N][N];
void input() {
    scanf("%d",&n);
    for ( int i=1; i<=n; i++ ) for ( int j=1; j<=n; j++ ) scanf("%d",g[i]+j);
}
int s[N][N];
int get( int x1, int y1, int x2, int y2 ) { return s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]; }
double ratio( int x, int y, int d ) {
    int lx=max(x-d,1),ly=max(y-d,1);
    int rx=min(x+d,n),ry=min(y+d,n);
    int all=(rx-lx+1)*(ry-ly+1),blk=get(lx,ly,rx,ry);
    return 1.0*blk/all;
}
int clr( int x, int y ) {
    double r=ratio(x,y,2);
    if ( r<0.2 ) return 0;
    if ( r>0.7 ) return 1;
    return g[x][y];
}
void build() {
    for ( int t=0; t<0; t++ ) {
        for ( int i=1; i<=n; i++ ) for ( int j=1; j<=n; j++ ) s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+g[i][j];
        for ( int i=1; i<=n; i++ ) for ( int j=1; j<=n; j++ ) g[i][j]=clr(i,j);
    }
    for ( int i=1; i<=n; i++ ) for ( int j=1; j<=n; j++ ) s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+g[i][j];
}
int nc,ns,np,q[N*N],fr,bk;
void push( int x ) { q[bk++]=x; }
int pop() { return q[fr++]; }
bool out( int x, int y ) { return x<1 || x>n || y<1 || y>n; }
void solve( int x, int y ) {
    const double gap=0.163;
    np=fr=bk=0;
    push(x); push(y);
    while ( fr!=bk ) {
        x=pop(); y=pop(); p[np++]=P(x,y);
        for ( int i=0; i<8; i++ ) {
            int nx=x+dx[i],ny=y+dy[i];
            if ( out(nx,ny) || !g[nx][ny] ) continue;
            push(nx); push(ny); g[nx][ny]=0;
        }
    }
    if ( np<50 ) return;
    double ax=0,ay=0,z=0;
    for ( int i=0; i<np; i++ ) ax+=p[i].x,ay+=p[i].y;
    ax/=np; ay/=np;
    for ( int i=0; i<np; i++ ) z+=sqr(p[i].x-ax)+sqr(p[i].y-ay);
    z/=1.0*np*np;
    //printf("%f\n",z);
    if ( z>=gap ) ns++;
    else nc++;
}
void solve() {
    for ( int i=1; i<=n; i++ ) for ( int j=1; j<=n; j++ ) if ( g[i][j] ) solve(i,j);
    printf("%d %d\n",nc,ns);
}
int main()
{
    input();
    build();
    solve();
    return 0;
}