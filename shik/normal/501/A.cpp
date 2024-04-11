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
    int a,b,c,d;
    RI(a,b,c,d);
    int x=max(3*a/10,a-a/250*c);
    int y=max(3*b/10,b-b/250*d);
    if ( x>y ) puts("Misha");
    else if ( x<y ) puts("Vasya");
    else puts("Tie");
    return 0;
}