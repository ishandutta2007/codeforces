// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
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

inline int two( int n ) { return 1<<n; }
const int N=21;
const int M=(1<<20)+10;

struct BIT {
    int dat[M],his[M],hn;
    void ins( int x, int v ) {
        if ( v==1 ) his[hn++]=x;
        for ( int i=x; i<M; i+=i&-i ) dat[i]+=v;
    }
    int ask( int x ) {
        int s=0;
        for ( int i=x; i; i-=i&-i ) s+=dat[i];
        return s;
    }
    void clear() {
        REP(i,hn) ins(his[i],-1);
        hn=0;
    }
} bit;

int n,a[M],l[M],ln;
LL np[N],rev[N],same[N];
int main() {
    RI(n);
    REP(i,1<<n) RI(a[i]);
    REP(i,1<<n) l[ln++]=a[i];
    sort(l,l+ln);
    ln=unique(l,l+ln)-l;
    REP(i,1<<n) a[i]=lower_bound(l,l+ln,a[i])-l+1;
    REP1(i,1,n) np[i]=1LL*two(i)*(two(i)-1)/2 * two(n)/two(i);
    REP1(i,1,n) {
        REP(j,1<<n) {
            if ( j%two(i)==0 ) bit.clear();
            if ( j%two(i)>=two(i-1) ) {
                int gt=two(i-1)-bit.ask(a[j]);
                int lt=bit.ask(a[j]-1);
                rev[i]+=gt;
                same[i]+=two(i-1)-gt-lt;
            } else {
                bit.ins(a[j],1);
            }
        }
    }
    REP1(i,1,n) rev[i]+=rev[i-1];
    REP1(i,1,n) same[i]+=same[i-1];
    int m,q;
    RI(m);
    while ( m-- ) {
        RI(q);
        LL nr=np[q]-same[q]-rev[q];
        REP1(i,q+1,n) rev[i]+=nr-rev[q];
        REP1(i,1,q) rev[i]=np[i]-same[i]-rev[i];
        printf("%I64d\n",rev[n]);
    }
    return 0;
}