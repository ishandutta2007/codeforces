// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 400010
struct Seg {
    bool cov[N];
    int pos[N];
    void ins( int id, int l, int r, int ql, int qr, int x ) {
        if ( r<ql || qr<l ) return;
        if ( ql<=l && r<=qr ) {
            cov[id]=1;
            pos[id]=l-ql+x;
            return;
        }
        int m=(l+r)/2;
        if ( cov[id] ) {
            cov[id]=0;
            cov[id*2]=cov[id*2+1]=1;
            pos[id*2]=pos[id];
            pos[id*2+1]=pos[id]+(m+1-l);
        }
        ins(id*2,l,m,ql,qr,x);
        ins(id*2+1,m+1,r,ql,qr,x);
    }
    int ask( int id, int l, int r, int x ) {
        if ( cov[id] ) return x-l+pos[id];
        if ( l==r ) return 0;
        int m=(l+r)/2;
        if ( x<=m ) return ask(id*2,l,m,x);
        else return ask(id*2+1,m+1,r,x);
    }
} seg;
int a[N],b[N];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
    for ( int i=1; i<=n; i++ ) scanf("%d",b+i);
    while ( m-- ) {
        int t;
        scanf("%d",&t);
        if ( t==1 ) {
            int x,y,k;
            scanf("%d%d%d",&x,&y,&k);
            seg.ins(1,1,n,y,y+k-1,x);
        } else {
            int x;
            scanf("%d",&x);
            int p=seg.ask(1,1,n,x);
            if ( p==0 ) printf("%d\n",b[x]);
            else printf("%d\n",a[p]);
        }
    }
    return 0;
}