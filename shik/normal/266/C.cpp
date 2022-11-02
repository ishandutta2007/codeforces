// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
inline void chkmax( int &a, int b ) { if ( b>a ) a=b; }
inline void chkmin( int &a, int b ) { if ( b<a ) a=b; }
int n,x[1010],y[1010];
int sn,sol[10000][3];
inline void add( int a, int b, int c ) {
    if ( b==c ) return;
    sol[sn][0]=a;
    sol[sn][1]=b;
    sol[sn][2]=c;
    sn++;
}
int main()
{
    scanf("%d",&n);
    for ( int i=1; i<=n; i++ ) scanf("%d%d",x+i,y+i);
    for ( int i=1; i<=n; i++ ) {
        int b[1010]={};
        for ( int j=1; j<=n; j++ ) chkmax(b[x[j]],y[j]);
        int w=i;
        for ( int j=i; j<=n; j++ ) if ( b[j]<b[w] ) w=j;
        add(1,w,i);
        for ( int j=1; j<=n; j++ ) {
            if ( x[j]==i ) x[j]=w;
            else if ( x[j]==w ) x[j]=i;
        }
    }
    for ( int i=1; i<=n; i++ ) swap(x[i],y[i]);
    for ( int i=1; i<=n; i++ ) {
        int b[1010]={};
        for ( int j=1; j<=n; j++ ) b[j]=1010;
        for ( int j=1; j<=n; j++ ) chkmin(b[x[j]],y[j]);
        int w=i;
        for ( int j=i; j<=n; j++ ) if ( b[j]<b[w] ) w=j;
        add(2,w,i);
        for ( int j=1; j<=n; j++ ) {
            if ( x[j]==i ) x[j]=w;
            else if ( x[j]==w ) x[j]=i;
        }
    }
    printf("%d\n",sn);
    for ( int i=0; i<sn; i++ ) printf("%d %d %d\n",sol[i][0],sol[i][1],sol[i][2]);
    return 0;
}