// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 210
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
template<typename T>
inline void chkmax( T &a, const T &b ) { if ( b>a ) a=b; }
template<typename T>
inline void chkmin( T &a, const T &b ) { if ( b<a ) a=b; }
pair<int,int> pr[N];
int n;
bool e[N][N];
int ans=(int)(1e8),w[N][N];
int solve( int a, int b ) {
    int sml=(int)(1e8);
    for ( int i=1; i<=n; i++ ) chkmin(sml,min(w[a][i],w[b][i]));
    //if ( sml>=ans ) return (int)(1e8);
    int l=0,r=(int)(2e7);
    while ( l!=r ) {
        int m=(l+r+1)/2;
        int pn=0;
        for ( int j=1; j<=n; j++ ) {
            int x=m-w[a][j];
            int y=w[a][b]-(m-w[b][j]);
            if ( x<0 ) x=0;
            if ( y>w[a][b] ) y=w[a][b];
            if ( x>y ) continue;
            pr[pn++]=make_pair(x,y);
        }
        sort(pr,pr+pn);
        int now=0;
        bool flg=0;
        for ( int i=0; i<pn&&now<w[a][b]; i++ ) {
            if ( pr[i].first>now ) {
                r=m-1;
                flg=1;
                break;
            }
            chkmax(now,pr[i].second);
        }
        if ( flg ) continue;
        if ( now>=w[a][b] ) l=m;
        else r=m-1;
    }
    return l;
}
int main()
{
    int m;
    scanf("%d%d",&n,&m);
    while ( m-- ) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        c*=2;
        e[a][b]=e[b][a]=c;
        w[a][b]=w[b][a]=c;
    }
    for ( int k=1; k<=n; k++ )
        for ( int i=1; i<=n; i++ ) if ( w[i][k] )
            for ( int j=1; j<=n; j++ ) if ( w[k][j] )
                if ( i!=j ) {
                    if ( !w[i][j] ) w[i][j]=w[i][k]+w[k][j];
                    else chkmin(w[i][j],w[i][k]+w[k][j]);
                }
    int far[N]={};
    for ( int i=1; i<=n; i++ ) for ( int j=1; j<=n; j++ ) chkmax(far[i],w[i][j]);
    for ( int i=1; i<=n; i++ ) chkmin(ans,far[i]);
    for ( int i=1; i<=n; i++ ) {
        for ( int j=i+1; j<=n; j++ ) if ( e[i][j] ) chkmin(ans,solve(i,j));
    }
    printf("%.12f\n",ans/2.);
    return 0;
}