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

char t[8][10]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
int main() {
    int n;
    char s[10];
    RI(n);
    scanf("%s",s);
    REP(i,8) if ( n==strlen(t[i]) ) {
        int cnt=0;
        REP(j,n) if ( s[j]=='.' || s[j]==t[i][j] ) cnt++;
        if ( cnt==n ) {
            puts(t[i]);
            return 0;
        }
    }
    return 0;
}