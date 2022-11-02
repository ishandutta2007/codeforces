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

struct DJS {
    int fa[N],sz[N];
    void init( int n ) {
        REP1(i,1,n) {
            fa[i]=i;
            sz[i]=1;
        }
    }
    int Find( int x ) {
        return x==fa[x]?x:fa[x]=Find(fa[x]);
    }
} djs;

struct E {
    int a,b,c;
    void read() {
        RI(a,b);
    }
} e[M];

inline bool operator <( const E &a, const E &b ) {
    return a.c<b.c;
}

int n,m,v[N];

int main() {
    RI(n,m);
    REP1(i,1,n) RI(v[i]);
    REP(i,m) e[i].read();
    REP(i,m) e[i].c=min(v[e[i].a],v[e[i].b]);
    sort(e,e+m);
    reverse(e,e+m);
    djs.init(n);
    double ans=0;
    REP(i,m) {
        int a=djs.Find(e[i].a);
        int b=djs.Find(e[i].b);
        if ( a==b ) continue;
        ans+=2.0*e[i].c*djs.sz[a]*djs.sz[b];
        djs.fa[a]=b;
        djs.sz[b]+=djs.sz[a];
    }
    ans/=1.0*n*(n-1);
    printf("%.9f\n",ans);
    return 0;
}