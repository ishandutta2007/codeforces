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
int n,k,p,a[N];
vector<int> v[2],sol[N];
int main() {
    RI(n,k,p);
    REP(i,n) RI(a[i]);
    int t[2]={p,k-p};
    REP(i,n) v[a[i]%2].PB(a[i]);
    if ( SZ(v[1])<t[1] ) return puts("NO"),0;
    REP(i,t[1]) {
        sol[i].PB(v[1].back());
        v[1].pop_back();
    }
    REP(i,t[0]) {
        if ( !v[0].empty() ) {
            sol[t[1]+i].PB(v[0].back());
            v[0].pop_back();
        } else if ( SZ(v[1])>=2 ) {
            sol[t[1]+i].PB(v[1].back());
            v[1].pop_back();
            sol[t[1]+i].PB(v[1].back());
            v[1].pop_back();
        } else {
            return puts("NO"),0;
        }
    }
    while ( !v[0].empty() ) {
        sol[0].PB(v[0].back());
        v[0].pop_back();
    }
    while ( SZ(v[1])>=2 ) {
        sol[0].PB(v[1].back());
        v[1].pop_back();
        sol[0].PB(v[1].back());
        v[1].pop_back();
    }
    if ( !v[1].empty() ) return puts("NO"),0;
    puts("YES");
    REP(i,k) {
        printf("%d",SZ(sol[i]));
        FOR(it,sol[i]) printf(" %d",*it);
        puts("");
    }
    return 0;
}