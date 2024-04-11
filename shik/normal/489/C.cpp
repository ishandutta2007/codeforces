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

int main() {
    int m,s;
    RI(m,s);
    int lb=(m>1?1:0);
    int rb=9*m;
    if ( s<lb || rb<s ) {
        puts("-1 -1");
        return 0;
    }
    int s1=0;
    REP(i,m) {
        REP(j,10) {
            if ( i==0 && m!=1 && j==0 ) continue;
            if ( s1+j+(m-i-1)*9<s ) continue;
            s1+=j;
            printf("%d",j);
            break;
        }
    }
    putchar(' ');
    int s2=0;
    REP(i,m) {
        for ( int j=9; j>=0; j-- ) {
            if ( s2+j>s ) continue;
            s2+=j;
            printf("%d",j);
            break;
        }
    }
    puts("");
    return 0;
}