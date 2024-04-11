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
        for ( int i=x; i<N; i+=i&-i ) dat[i]=max(dat[i],v);
    }
    int ask( int x ) {
        int r=0;
        for ( int i=x; i; i-=i&-i ) r=max(r,dat[i]);
        return r;
    }
} bit;

int n,l[N],r[N];
void input() {
    RI(n);
    REP1(i,1,n) {
        RI(l[i],r[i]);
        r[i]+=l[i];
    }
}

int rmq[18][N],to[18][N],w[18][N];

int get_max( int st, int ed ) {
    int lv=__lg(ed-st+1);
    return max(rmq[lv][st],rmq[lv][ed-(1<<lv)+1]);
}

void build() {
    REP1(i,1,n) rmq[0][i]=r[i];
    REP(i,17) {
        int ub=n-(1<<i)-(1<<i)+1;
        REP1(j,1,ub) rmq[i+1][j]=max(rmq[i][j],rmq[i][j+(1<<i)]);
    }
    REP(i,18) to[i][n+1]=n+1;
    for ( int i=n; i>=1; i-- ) {
        int j=upper_bound(l+1,l+n+1,r[i])-l;
        j=max(j,bit.ask(j-1));
        bit.ins(i,j);
        to[0][i]=j;
        if ( j==n+1 ) w[0][i]=0;
        else w[0][i]=l[j]-get_max(i,j-1);
    }
    REP(i,17) REP1(j,1,n) {
        to[i+1][j]=to[i][to[i][j]];
        w[i+1][j]=w[i][j]+w[i][to[i][j]];
    }
}

void solve() {
    int q,x,y;
    RI(q);
    while ( q-- ) {
        RI(x,y);
        int ans=0;
        for ( int i=17; i>=0; i-- ) {
            if ( to[i][x]>y ) continue;
            ans+=w[i][x];
            x=to[i][x];
        }
        printf("%d\n",ans);
    }
}

int main() {
    input();
    build();
    solve();
    return 0;
}