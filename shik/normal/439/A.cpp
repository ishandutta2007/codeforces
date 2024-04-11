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

#define N 110
int n,d,a[N];
int main() {
    RI(n,d);
    REP(i,n) RI(a[i]);
    int s=0;
    REP(i,n) s+=a[i];
    s+=10*(n-1);
    if ( s>d ) puts("-1");
    else printf("%d\n",2*(n-1)+(d-s)/5);
    return 0;
}