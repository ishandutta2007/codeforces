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
int n,a[N];

int main() {
    RI(n);
    REP1(i,1,n) RI(a[i]);
    if ( a[n]==1 ) return puts("NO"),0;
    if ( n==1 ) {
        puts("YES");
        puts("0");
        return 0;
    }
    if ( a[n-1]==1 ) {
        puts("YES");
        REP1(i,1,n) printf("%d%s",a[i],i<n?"->":"\n");
        return 0;
    }
    for ( int i=1; i<n-1; i++ ) if ( a[i]==0 ) {
        puts("YES");
        REP1(j,1,n) {
            if ( j==i || j==i+1 ) putchar('(');
            printf("%d",a[j]);
            if ( j==n-1 ) printf("))");
            printf(j<n?"->":"\n");
        }
        return 0;
    }
    puts("NO");
    return 0;
}