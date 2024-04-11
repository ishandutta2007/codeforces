// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 16
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,a[16],s,b[N][N];
bool chk() {
    for ( int i=0; i<n; i++ ) for ( int j=0; j<n; j++ ) b[i][j]=a[i*n+j];
    for ( int i=0; i<n; i++ ) {
        int t=0;
        for ( int j=0; j<n; j++ ) t+=b[i][j];
        if ( t!=s ) return 0;
        t=0;
        for ( int j=0; j<n; j++ ) t+=b[j][i];
        if ( t!=s ) return 0;
    }
    int t1=0,t2=0;
    for ( int i=0; i<n; i++ ) t1+=b[i][i],t2+=b[i][n-i-1];
    return t1==s && t2==s;
}
void lasai() {
    sort(a,a+n*n);
    while ( !chk() && next_permutation(a,a+n*n) );
    for ( int i=0; i<n; i++ ) for ( int j=0; j<n; j++ ) printf("%d%c",b[i][j],j==n-1?'\n':' ');
}
int sx[N]={0,1,2,3,0,1,2,3,0,0,3,3,1,1,2,2};
int sy[N]={0,1,2,3,3,2,1,0,1,2,2,1,0,3,3,0};
int sz[N]={0,0,0,3,0,0,0,4,0,1,2,5,0,1,2,5};
int cx[N],cy[N],cz[2],vis[N];
void add( int x, int y, int v ) {
    cx[x]+=v;
    cy[y]+=v;
    if ( x==y ) cz[0]+=v;
    if ( x==n-y-1 ) cz[1]+=v;
}
int get( int x ) {
    for ( int i=0; i<n*n; i++ ) if ( !vis[i] && a[i]==x ) return i;
    return -1;
}
bool go( int p ) {
    if ( p==n*n ) {
        //if ( !chk() ) return 0;
        for ( int i=0; i<n; i++ ) for ( int j=0; j<n; j++ ) printf("%d%c",b[i][j],j==n-1?'\n':' ');
        return 1;
    }
    int x=sx[p],y=sy[p],z=sz[p];
    if ( z==0 ) {
        for ( int i=0; i<n*n; i++ ) if ( !vis[i] ) {
            b[x][y]=a[i];
            vis[i]=1;
            add(x,y,a[i]);
            if ( go(p+1) ) return 1;
            add(x,y,-a[i]);
            vis[i]=0;
        }
    } else {
        int v,w;
        if ( z==1 ) v=s-cx[x];
        else if ( z==2 ) v=s-cy[y];
        else if ( z==3 ) v=s-cz[0];
        else if ( z==4 ) v=s-cz[1];
        else if ( z==5 ) {
            if ( cx[x]!=cy[y] ) return 0;
            v=s-cx[x];
        }
        b[x][y]=v;
        w=get(v);
        if ( w!=-1 ) {
            vis[w]=1;
            add(x,y,v);
            if ( go(p+1) ) return 1;
            add(x,y,-v);
            vis[w]=0;
        }
    }
    return 0;
}
void solve() {
    sort(a,a+n*n);
    go(0);
}
int main()
{
    scanf("%d",&n);
    for ( int i=0; i<n*n; i++ ) scanf("%d",a+i);
    for ( int i=0; i<n*n; i++ ) s+=a[i];
    s/=n;
    printf("%d\n",s);
    if ( n<=3 ) lasai();
    else solve();
    return 0;
}