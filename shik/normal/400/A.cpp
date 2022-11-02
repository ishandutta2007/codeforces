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

char s[13];
void input() {
    scanf("%s",s);
}

bool check( int a, int b ) {
    REP(i,b) {
        bool good=1;
        REP(j,a) good&=s[j*b+i]=='X';
        if ( good ) return 1;
    }
    return 0;
}

void solve() {
    vector<PII> sol;
    REP1(i,1,12) if ( 12%i==0 && check(i,12/i) ) sol.PB(MP(i,12/i));
    printf("%d",SZ(sol));
    FOR(it,sol) printf(" %dx%d",it->first,it->second);
    puts("");
}

int main() {
    int t;
    RI(t);
    while ( t-- ) {
        input();
        solve();
    }
    return 0;
}