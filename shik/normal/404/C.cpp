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

#define N 100010
int n,k,d[N];
VI vd[N];
vector<PII> sol;
bool check() {
    static int deg[N];
    FOR(it,sol) {
        deg[it->first]++;
        deg[it->second]++;
    }
    REP1(i,1,n) if ( deg[i]>k ) return 0;
    return 1;
}
int main() {
    RI(n,k);
    REP1(i,1,n) RI(d[i]);
    REP1(i,1,n) vd[d[i]].PB(i);
    REP1(i,1,n) if ( !vd[i].empty() && vd[i-1].empty() ) return puts("-1"),0;
    if ( SZ(vd[0])!=1 ) return puts("-1"),0;
    REP1(i,1,n) {
        int j=0;
        FOR(it,vd[i]) {
            sol.PB(MP(vd[i-1][j],*it));
            j=(j+1)%SZ(vd[i-1]);
        }
    }
    if ( !check() ) puts("-1");
    else {
        printf("%d\n",SZ(sol));
        FOR(it,sol) printf("%d %d\n",it->first,it->second);
    }
    return 0;
}