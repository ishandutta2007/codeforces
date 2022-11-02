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
int n,h[N];

bool chk( int m ) {
    REP1(i,1,n) {
        m+=h[i-1]-h[i];
        if ( m<0 ) return 0;
    }
    return 1;
}

int main() {
    RI(n);
    REP1(i,1,n) RI(h[i]);
    int l=0,r=1e9;
    while ( l!=r ) {
        int m=(l+r)/2;
        if ( chk(m) ) r=m;
        else l=m+1;
    }
    printf("%d\n",l);
    return 0;
}