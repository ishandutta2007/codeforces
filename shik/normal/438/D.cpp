// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
// }}}

#define N 400010
struct Seg {
    int n,*a,big[N];
    LL s[N];
    void pull( int id ) {
        big[id]=a[big[id*2]]>a[big[id*2+1]]?big[id*2]:big[id*2+1];
        s[id]=s[id*2]+s[id*2+1];
    }
    void init( int id, int l, int r ) {
        if ( l==r ) {
            big[id]=l;
            s[id]=a[l];
            return;
        }
        int m=(l+r)/2;
        init(id*2,l,m);
        init(id*2+1,m+1,r);
        pull(id);
    }
    void init( int _n, int _a[N] ) {
        n=_n;
        a=_a;
        init(1,1,n);
    }
    void chg( int id, int l, int r, int p, int v ) {
        if ( l==r ) {
            big[id]=p;
            a[l]=s[id]=v;
            return;
        }
        int m=(l+r)/2;
        if ( p<=m ) chg(id*2,l,m,p,v);
        else chg(id*2+1,m+1,r,p,v);
        pull(id);
    }
    int ask_big( int id, int l, int r, int ql, int qr ) {
        if ( ql<=l && r<=qr ) return big[id];
        int m=(l+r)/2;
        if ( qr<=m ) return ask_big(id*2,l,m,ql,qr);
        else if ( ql>m ) return ask_big(id*2+1,m+1,r,ql,qr);
        else {
            int x=ask_big(id*2,l,m,ql,qr);
            int y=ask_big(id*2+1,m+1,r,ql,qr);
            return a[x]>a[y]?x:y;
        }
    }
    LL ask_sum( int id, int l, int r, int ql, int qr ) {
        if ( ql<=l && r<=qr ) return s[id];
        int m=(l+r)/2;
        if ( qr<=m ) return ask_sum(id*2,l,m,ql,qr);
        else if ( ql>m ) return ask_sum(id*2+1,m+1,r,ql,qr);
        else {
            LL x=ask_sum(id*2,l,m,ql,qr);
            LL y=ask_sum(id*2+1,m+1,r,ql,qr);
            return x+y;
        }
    }
} seg;

int n,m,a[N];
int main() {
    RI(n,m);
    REP1(i,1,n) RI(a[i]);
    seg.init(n,a);
    while ( m-- ) {
        int op;
        RI(op);
        if ( op==1 ) {
            int l,r;
            RI(l,r);
            LL ans=seg.ask_sum(1,1,n,l,r);
            cout<<ans<<endl;
        } else if ( op==2 ) {
            int l,r,x;
            RI(l,r,x);
            while ( 1 ) {
                int p=seg.ask_big(1,1,n,l,r);
                if ( a[p]<x ) break;
                seg.chg(1,1,n,p,a[p]%x);
            }
        } else if ( op==3 ) {
            int k,x;
            RI(k,x);
            seg.chg(1,1,n,k,x);
        } else puts("QQ");
    }
    return 0;
}