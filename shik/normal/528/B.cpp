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

struct P {
    int l,r;
    void read() {
        int x,w;
        RI(x,w);
        l=x-w;
        r=x+w;
    }
} p[N];

int n,xs[N],xn,to[N],dp[N];

int shik( int x ) {
    return lower_bound(xs,xs+xn,x)-xs+1;
}

int main() {
    RI(n);
    REP(i,n) p[i].read();
    REP(i,n) {
        xs[xn++]=p[i].l;
        xs[xn++]=p[i].r;
    }
    sort(xs,xs+xn);
    xn=unique(xs,xs+xn)-xs;
    REP(i,n) {
        p[i].l=shik(p[i].l);
        p[i].r=shik(p[i].r);
    }
    REP(i,n) {
        if ( !to[p[i].l] ) to[p[i].l]=p[i].r;
        else to[p[i].l]=min(to[p[i].l],p[i].r);
    }
    for ( int i=xn-1; i>=1; i-- ) {
        dp[i]=dp[i+1];
        if ( to[i] ) dp[i]=max(dp[i],dp[to[i]]+1);
    }
    printf("%d\n",dp[1]);
    return 0;
}