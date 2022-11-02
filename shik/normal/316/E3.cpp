// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 200010
#define MOD 1000000000
inline int sub( int a, int b ) {
    a-=b;
    if ( a<0 ) a+=MOD;
    return a;
}
inline void subi( int &a, int b ) {
    a-=b;
    if ( a<0 ) a+=MOD;
}
inline void addi( int &a, int b ) {
    a+=b;
    if ( a>=MOD ) a%=MOD;
}
inline int mul( int a, int b ) { return 1LL*a*b%MOD; }
struct Mat {
    int dat[2][2];
    int* operator[]( int idx ) { return dat[idx]; }
    const int* operator[]( int idx ) const { return dat[idx]; }
    void print() { printf("[%d %d; %d %d]\n",dat[0][0],dat[0][1],dat[1][0],dat[1][1]); }
} A[N],SA[N],Z;
Mat operator +( Mat a, const Mat &b ) {
    for ( int i=0; i<2; i++ ) for ( int j=0; j<2; j++ ) addi(a[i][j],b[i][j]);
    return a;
}
Mat operator *( const Mat &a, const Mat &b ) {
    Mat c;
    for ( int i=0; i<2; i++ ) for ( int j=0; j<2; j++ ) {
        c[i][j]=0;
        for ( int k=0; k<2; k++ ) addi(c[i][j],mul(a[i][k],b[k][j]));
    }
    return c;
}
Mat inv( const Mat &a ) {
    Mat b;
    int det=sub(mul(a[0][0],a[1][1]),mul(a[0][1],a[1][0])); // +1 or -1
    if ( det==1 ) {
        b[0][0]=a[1][1];
        b[1][1]=a[0][0];
        b[0][1]=MOD-a[0][1];
        b[1][0]=MOD-a[1][0];
    } else if ( det==MOD-1 ) {
        b[0][0]=MOD-a[1][1];
        b[1][1]=MOD-a[0][0];
        b[0][1]=a[0][1];
        b[1][0]=a[1][0];
    } else puts("QQ");
    return b;
}
Mat operator /( const Mat &a, const Mat &b ) {
    return a * inv(b);
}
Mat operator *( int a, Mat b ) {
    for ( int i=0; i<2; i++ ) for ( int j=0; j<2; j++ ) b[i][j]=mul(a,b[i][j]);
    return b;
}
Mat operator -( Mat a, const Mat &b ) {
    for ( int i=0; i<2; i++ ) for ( int j=0; j<2; j++ ) subi(a[i][j],b[i][j]);
    return a;
}
struct Seg {
    Mat s[4*N],ss[4*N];
    int d[4*N];
    Mat get( int id, int l, int r ) {
        return s[id] + d[id] * ss[id];
    }
#define pull s[id]=get(id*2,l,m)+get(id*2+1,m+1,r)
#define push { \
    addi(d[id*2],d[id]); \
    addi(d[id*2+1],d[id]); \
    d[id]=0; \
}
    void init( int id, int l, int r, int a[] ) {
        d[id]=0;
        ss[id]=SA[r]-SA[l-1];
        if ( l==r ) {
            s[id]=a[l]*A[l];
        } else {
            int m=(l+r)/2;
            init(id*2,l,m,a);
            init(id*2+1,m+1,r,a);
            pull;
        }
    }
    Mat ask( int id, int l, int r, int ql, int qr ) {
        if ( ql<=l && r<=qr ) return get(id,l,r);
        bool pp=d[id];
        if ( pp ) push;
        int m=(l+r)/2;
        Mat ret;
        if ( ql<=m && qr>m ) ret=ask(id*2,l,m,ql,qr)+ask(id*2+1,m+1,r,ql,qr);
        else if ( ql<=m ) ret=ask(id*2,l,m,ql,qr);
        else ret=ask(id*2+1,m+1,r,ql,qr);
        if ( pp ) pull;
        return ret;
    }
    void let( int id, int l, int r, int p, int v ) {
        if ( l==r ) {
            s[id]=v*A[p];
            d[id]=0;
            return;
        }
        int m=(l+r)/2;
        push;
        if ( p<=m ) let(id*2,l,m,p,v);
        else let(id*2+1,m+1,r,p,v);
        pull;
    }
    void add( int id, int l, int r, int ql, int qr, int qd ) {
        if ( ql<=l && r<=qr ) {
            addi(d[id],qd);
            return;
        }
        int m=(l+r)/2;
        push;
        if ( ql<=m ) add(id*2,l,m,ql,qr,qd);
        if ( qr>m ) add(id*2+1,m+1,r,ql,qr,qd);
        pull;
    }
} seg;
int a[N];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
    A[0][0][0]=A[0][0][1]=A[0][1][0]=1;
    A[0][1][1]=0;
    for ( int i=1; i<=n; i++ ) A[i]=A[i-1]*A[0];
    SA[0]=A[0];
    for ( int i=1; i<=n; i++ ) SA[i]=SA[i-1]+A[i];
    seg.init(1,1,n,a);
    while ( m-- ) {
        int t;
        scanf("%d",&t);
        if ( t==1 ) {
            int x,v;
            scanf("%d%d",&x,&v);
            seg.let(1,1,n,x,v);
        } else if ( t==2 ) {
            int l,r;
            scanf("%d%d",&l,&r);
            Mat M1=seg.ask(1,1,n,l,r);
            Mat M2=M1/A[l];
            printf("%d\n",M2[0][0]);
        } else if ( t==3 ) {
            int l,r,d;
            scanf("%d%d%d",&l,&r,&d);
            seg.add(1,1,n,l,r,d);
        } else puts("QQQ");
    }
    return 0;
}