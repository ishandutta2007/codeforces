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

#define N 55

int main() {
    int n;
    LL m;
    cin>>n>>m;
    int p[N],l=1,r=n;
    for ( int i=1; i<n; i++ ) {
        LL x=1LL<<(r-l-1);
        if ( m<=x ) {
            p[l++]=i;
        } else {
            m-=x;
            p[r--]=i;
        }
    }
    assert(l==r);
    p[l]=n;
    REP1(i,1,n) printf("%d%c",p[i],i==n?'\n':' ');
    return 0;
}