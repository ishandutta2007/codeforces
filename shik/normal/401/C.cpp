// by shik {{{
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(c) begin(c),end(c)
#define REP(i,n) for ( int i=0; i<(int)(n); i++ )
#define REP1(i,a,b) for ( int i=(int)(a); i<=(int)(b); i++ )
#define FOR(it,c) for (auto it=begin(c); it!=end(c); it++)
#define MP make_pair
#define PB push_back
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
/// }}}

int main() {
    int n,m;
    RI(n,m);
    if ( m<n-1 || m>2*n+2 ) puts("-1");
    else {
        VI v(n+1,2);
        int s=2*n+2;
        REP(i,n+1) if ( s>m ) {
            s--;
            v[i]--;
        }
        if ( s>m ) v[0]--,s--;
        if ( s>m ) v[n]--,s--;
        REP(i,n) {
            while ( v[i]-- ) putchar('1');
            putchar('0');
        }
        while ( v[n]-- ) putchar('1');
        puts("");
    }
    return 0;
}