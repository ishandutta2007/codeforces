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

struct E {
    int a,b,c;
    void read() {
        RI(a,b,c);
    }
} es[N];

int n;
VI e[N];

bool vis[N];
int dep[N],sz[N];
int go( int p, int lv ) {
    vis[p]=1;
    dep[p]=lv;
    sz[p]=1;
    FOR(it,e[p]) {
        auto &ee=es[*it];
        int to=p^ee.a^ee.b;
        if ( vis[to] ) continue;
        sz[p]+=go(to,lv+1);
    }
    return sz[p];
}

double f( double x ) {
    return x*(x-1)/2;
}

double z[N];
int main() {
    RI(n);
    REP1(i,1,n-1) es[i].read();
    REP1(i,1,n-1) {
        e[es[i].a].PB(i);
        e[es[i].b].PB(i);
    }
    go(1,1);
    REP1(i,1,n-1) {
        int a=es[i].a;
        int b=es[i].b;
        if ( dep[a]>dep[b] ) swap(a,b);
        int x=sz[b],y=n-x;
        z[i]=2*(f(x)*y+f(y)*x);
    }
    double base=1.0*n*(n-1)*(n-2)/6;
    double s=0;
    REP1(i,1,n-1) s+=z[i]*es[i].c;
    int q;
    RI(q);
    while ( q-- ) {
        int i,c;
        RI(i,c);
        s-=z[i]*es[i].c;
        es[i].c=c;
        s+=z[i]*es[i].c;
        printf("%.9f\n",s/base);
    }
    return 0;
}