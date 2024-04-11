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

#define N 100010
#define M 100010
#define C 300

struct Q {
    int op,l,r,x;
    void read() {
        RI(op,l,r);
        if ( op==1 ) RI(x);
    }
} q[M];


int n,m,c[N];
LL v[N];

struct B {
    int l,r;
    LL s;
    vector<int> vq;
    B() {}
    B( int _l, int _r ):l(_l),r(_r),s(0) {
        //printf("(%d, %d)\n",l,r);
        REP1(i,l,r) s+=v[i];
        vq.clear();
    }
    void add_q( int x ) {
        //printf("(%d, %d) add %d\n",l,r,x);
        if ( vq.empty() ) {
            REP1(i,l,r) s+=abs(x-c[i]);
        } else {
            s+=(r-l+1LL)*abs(x-vq.back());
        }
        vq.PB(x);
    }
    void flat() {
        //printf("(%d, %d) flat\n",l,r);
        if ( vq.empty() ) return;
        LL d=0;
        REP1(i,1,SZ(vq)-1) d+=abs(vq[i]-vq[i-1]);
        REP1(i,l,r) v[i]+=abs(c[i]-vq[0])+d;
        REP1(i,l,r) c[i]=vq.back();
    }
} b[N];

int main() {
    RI(n,m);
    REP(i,m) q[i].read();
    REP1(i,1,n) c[i]=i;
    int qi=0;
    while ( qi+C<=m ) {
        vector<int> vp{1,n+1};
        REP(j,C) {
            vp.PB(q[qi+j].l);
            vp.PB(q[qi+j].r+1);
        }
        sort(ALL(vp));
        vp.erase(unique(ALL(vp)),vp.end());
        int bn=0;
        REP(i,SZ(vp)-1) b[bn++]=B(vp[i],vp[i+1]-1);
        REP(j,C) {
            int op=q[qi+j].op;
            int l=q[qi+j].l;
            int r=q[qi+j].r;
            int x=q[qi+j].x;
            if ( op==1 ) {
                REP(i,bn) if ( l<=b[i].l && b[i].r<=r ) b[i].add_q(x);
            } else {
                LL ans=0;
                REP(i,bn) if ( l<=b[i].l && b[i].r<=r ) ans+=b[i].s;
                cout<<ans<<endl;
            }
        }
        REP(i,bn) b[i].flat();
        qi+=C;
    }
    while ( qi<m ) {
        int op=q[qi].op;
        int l=q[qi].l;
        int r=q[qi].r;
        int x=q[qi].x;
        if ( op==1 ) {
            REP1(i,l,r) {
                v[i]+=abs(x-c[i]);
                c[i]=x;
            }
        } else {
            LL ans=0;
            REP1(i,l,r) ans+=v[i];
            cout<<ans<<endl;
        }
        qi++;
    }
    return 0;
}