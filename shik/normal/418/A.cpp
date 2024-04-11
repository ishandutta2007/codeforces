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

int main() {
    int n,k;
    RI(n,k);
    if ( k>=(n+1)/2 ) puts("-1");
    else {
        int m=n*k;
        printf("%d\n",m);
        REP1(i,1,n) REP1(j,1,k) printf("%d %d\n",i,i+j>n?i+j-n:i+j);
    }
    return 0;
}