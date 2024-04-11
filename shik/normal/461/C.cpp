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

#define N 200010
struct BIT {
    int dat[N];
    void ins( int x, int v ) {
        for ( int i=x; i<N; i+=i&-i ) dat[i]+=v;
    }
    int ask( int x ) {
        int s=0;
        for ( int i=x; i; i-=i&-i ) s+=dat[i];
        return s;
    }
    int ask( int l, int r ) {
        return ask(r)-ask(l-1);
    }
    int operator[]( int i ) { return ask(i,i); }
} bit;

int n,m;
int main() {
    RI(n,m);
    REP1(i,1,n) bit.ins(i,1);
    bool rev=0;
    int st=1,ed=n;
    auto foldl=[&]( int p ) {
        int rb=st+p+p-1;
        REP(i,p) bit.ins(rb-i,bit[st+i]);
        st+=p;
    };
    auto foldr=[&]( int p ) {
        int lb=ed-p-p+1;
        REP(i,p) bit.ins(lb+i,bit[ed-i]);
        ed-=p;
    };
    while ( m-- ) {
        int op;
        RI(op);
        if ( op==1 ) {
            int p;
            RI(p);
            int len=ed-st+1;
            if ( p>len-p ) {
                rev^=1;
                p=len-p;
            }
            if ( !rev ) foldl(p);
            else foldr(p);
        } else if ( op==2 ) {
            int l,r;
            RI(l,r);
            if ( !rev ) printf("%d\n",bit.ask(st+l,st+r-1));
            else printf("%d\n",bit.ask(ed-r+1,ed-l));
        }
    }
    return 0;
}