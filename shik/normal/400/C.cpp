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

#define P 100010
int x[P],y[P];
int main() {
    int n,m,a,b,c,p;
    RI(n,m,a,b,c,p);
    REP(i,p) RI(x[i],y[i]);
    a%=4; b%=2; c%=4;
    while ( a-- ) {
        REP(i,p) tie(x[i],y[i])=make_tuple(y[i],n-x[i]+1);
        swap(n,m);
    }
    while ( b-- ) REP(i,p) y[i]=m-y[i]+1;
    while ( c-- ) {
        REP(i,p) tie(x[i],y[i])=make_tuple(m-y[i]+1,x[i]);
        swap(n,m);
    }
    REP(i,p) printf("%d %d\n",x[i],y[i]);
    return 0;
}