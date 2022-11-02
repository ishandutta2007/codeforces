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

char t0[]="QRBNP";
char t1[]="qrbnp";
int v[]={9,5,3,3,1};

int main() {
    char s[20];
    int s0=0,s1=0;
    while ( gets(s) ) {
        for ( int i=0; s[i]; i++ ) {
            if ( strchr(t0,s[i]) ) s0+=v[strchr(t0,s[i])-t0];
            if ( strchr(t1,s[i]) ) s1+=v[strchr(t1,s[i])-t1];
        }
    }
    if ( s0>s1 ) puts("White");
    else if ( s0<s1 ) puts("Black");
    else puts("Draw");
    return 0;
}