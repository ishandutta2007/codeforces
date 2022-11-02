// shik {{{
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

const int N=400010;
const int M=400010;
struct E {
    int a,b;
} es[M];

int n,m,old_m;
VI e[N];

void add_edge( int a, int b ) {
    e[a].PB(m);
    e[b].PB(m);
    es[m++]=E{a,b};
}

void input() {
    n=N;
    RI(old_m);
    REP(i,old_m) {
        int a,b;
        RI(a,b);
        add_edge(a,b+200000);
    }
}

void build() {
    old_m=m;
    VI odd;
    REP(i,n) if ( SZ(e[i])%2==1 ) odd.PB(i);
    assert(SZ(odd)%2==0);
    for ( int i=0; i<SZ(odd); i+=2 ) add_edge(odd[i],odd[i+1]);
}

int sol[M];
bool vis[M];
void dfs( int p ) {
    while ( !e[p].empty() ) {
        int i=e[p].back();
        e[p].pop_back();
        if ( vis[i] ) continue;
        auto &ee=es[i];
        vis[i]=1;
        sol[i]=(p==ee.b);
        dfs(p^ee.a^ee.b);
    }
}

void solve() {
    REP(i,m) vis[i]=0;
    REP(i,n) dfs(i);
    REP(i,old_m) putchar("rb"[sol[i]]);
    puts("");
}

int main() {
    input();
    build();
    solve();
    return 0;
}