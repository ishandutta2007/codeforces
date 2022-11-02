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
vector<int> e[N];

int init[N],goal[N];

VI sol;

void go( int p, int f, int x, int y ) {
    if ( (init[p]^x)!=goal[p] ) {
        sol.PB(p);
        x^=1;
    }
    FOR(it,e[p]) if ( *it!=f ) go(*it,p,y,x);
}

int main() {
    int n;
    RI(n);
    REP(i,n-1) {
        int a,b;
        RI(a,b);
        e[a].PB(b);
        e[b].PB(a);
    }
    REP1(i,1,n) RI(init[i]);
    REP1(i,1,n) RI(goal[i]);
    go(1,0,0,0);
    sort(ALL(sol));
    printf("%d\n",SZ(sol));
    FOR(it,sol) printf("%d\n",*it);
    return 0;
}