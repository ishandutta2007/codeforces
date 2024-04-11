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
    long double m,n;
    cin>>m>>n;
    long double ans=0;
    REP1(i,1,m) {
        long double p=powl(i/m,n);
        if ( i>1 ) p-=powl((i-1)/m,n);
        ans+=p*i;
    }
    printf("%.9f\n",(double)ans);
    return 0;
}