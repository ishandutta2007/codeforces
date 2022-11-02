// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
#define ALL(x) begin(x),end(x)
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

void go( int n, int a[] ) {
    if ( n==1 ) a[1]=1;
    else if ( n==2 ) a[1]=3,a[2]=4;
    else {
        a[1]=n-2;
        REP1(i,2,n) a[i]=2;
        // (n-1) * 2^2 + (n-2)^2 = 4n - 4 + n^2 - 4n + 4 = n^2
    }
}

int main() {
    int n,m,a[110],b[110];
    RI(n,m);
    go(n,a);
    go(m,b);
    REP1(i,1,n) REP1(j,1,m) printf("%d%c",a[i]*b[j],j==m?'\n':' ');
    return 0;
}