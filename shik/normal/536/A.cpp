// {{{ by shik
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
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

int a,b;
LL get( int i ) {
    return a+(i-1LL)*b;
}
bool chk( int l, int r, int t, int m ) {
    LL cl=get(l);
    LL cr=get(r);
    if ( cr>t ) return 0;
    LL s=(cl+cr)*(r-l+1)/2;
    if ( s>1LL*t*m ) return 0;
    return 1;
}

int main() {
    int n;
    RI(a,b,n);
    while ( n-- ) {
        int l,t,m;
        RI(l,t,m);
        int ll=l,rr=l+1e7;
        while ( ll!=rr ) {
            int mm=(ll+rr+1)/2;
            if ( chk(l,mm,t,m) ) ll=mm;
            else rr=mm-1;
        }
        if ( chk(l,ll,t,m) ) printf("%d\n",ll);
        else puts("-1");
    }
    return 0;
}