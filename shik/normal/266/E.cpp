// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 100010
#define SN (4*N)
#define MOD 1000000007
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
LL add( LL a, LL b ) { return (a+b)%MOD; }
LL sub( LL a, LL b ) { return (a-b+MOD)%MOD; }
LL mul( LL a, LL b ) { return a*b%MOD; }
struct Seg {
    LL cov[SN],sum[SN],*pw,*spw;
    void init( int id, int l, int r, int a[] ) {
        if ( l==r ) {
            cov[id]=a[l];
            sum[id]=mul(a[l],pw[l]);
            return;
        }
        int m=(l+r)/2;
        init(id*2,l,m,a);
        init(id*2+1,m+1,r,a);
        cov[id]=-1;
        sum[id]=sum[id*2]+sum[id*2+1];
    }
    void push( int id, int l, int m, int r ) {
        if ( cov[id]==-1 ) return;
        cov[id*2]=cov[id*2+1]=cov[id];
        sum[id*2]=mul(cov[id],sub(spw[m],spw[l-1]));
        sum[id*2+1]=mul(cov[id],sub(spw[r],spw[m]));
        cov[id]=-1;
    }
    void pull( int id ) {
        if ( cov[id]!=-1 ) puts("QQ");
        sum[id]=sum[id*2]+sum[id*2+1];
    }
    LL ask( int id, int l, int r, int ql, int qr ) {
        if ( qr<l || ql>r ) return 0;
        if ( ql<=l && r<=qr ) return sum[id];
        int m=(l+r)/2;
        push(id,l,m,r);
        LL ret=add(ask(id*2,l,m,ql,qr),ask(id*2+1,m+1,r,ql,qr));
        pull(id);
        return ret;
    }
    void set( int id, int l, int r, int ql, int qr, int x ) {
        if ( qr<l || ql>r ) return;
        if ( ql<=l && r<=qr ) {
            cov[id]=x;
            sum[id]=mul(x,sub(spw[r],spw[l-1]));
            return;
        }
        int m=(l+r)/2;
        push(id,l,m,r);
        set(id*2,l,m,ql,qr,x);
        set(id*2+1,m+1,r,ql,qr,x);
        pull(id);
    }
} seg[6];
int a[N];
LL pw[6][N],spw[6][N],C[10][10];
int main()
{
    for ( int i=0; i<10; i++ ) for ( int j=C[i][0]=1; j<=i; j++ ) C[i][j]=C[i-1][j]+C[i-1][j-1];
    for ( int i=0; i<N; i++ ) pw[0][i]=1;
    for ( int i=1; i<6; i++ ) for ( int j=0; j<N; j++ ) pw[i][j]=mul(pw[i-1][j],j);
    for ( int i=0; i<6; i++ ) for ( int j=1; j<N; j++ ) spw[i][j]=add(spw[i][j-1],pw[i][j]);
    int n,m;
    scanf("%d%d",&n,&m);
    for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
    for ( int i=0; i<6; i++ ) seg[i].pw=pw[i];
    for ( int i=0; i<6; i++ ) seg[i].spw=spw[i];
    for ( int i=0; i<6; i++ ) seg[i].init(1,1,n,a);
    while ( m-- ) {
        char op;
        int l,r,x;
        scanf(" %c%d%d%d",&op,&l,&r,&x);
        if ( op=='=' ) {
            for ( int i=0; i<6; i++ ) seg[i].set(1,1,n,l,r,x);
        } else {
            LL ans=0;
            for ( int i=0; i<=x; i++ ) {
                if ( (x-i)%2==0 ) ans=add(ans,mul(mul(C[x][i],pw[x-i][l-1]),seg[i].ask(1,1,n,l,r)));
                else ans=sub(ans,mul(mul(C[x][i],pw[x-i][l-1]),seg[i].ask(1,1,n,l,r)));
            }
            printf("%d\n",(int)ans);
        }
    }
    return 0;
}