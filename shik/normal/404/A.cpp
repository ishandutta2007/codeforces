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

char s[310][310];
int main() {
    int n;
    RI(n);
    REP(i,n) scanf("%s",s[i]);
    char c=s[0][0];
    bool good=1;
    REP(i,n) if ( s[i][i]!=c || s[i][n-i-1]!=c ) good=0;
    char d=s[0][1];
    if ( c==d ) good=0;
    REP(i,n) REP(j,n) if ( i!=j && j!=n-i-1 && s[i][j]!=d ) good=0;
    puts(good?"YES":"NO");
    return 0;
}