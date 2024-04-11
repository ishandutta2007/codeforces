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

#define N 1000010
bool c[N];
int main() {
    for ( int i=2; i<1000; i++ ) if ( !c[i] )
        for ( int j=i+i; j<N; j+=i ) c[j]=1;
    int n;
    RI(n);
    REP1(i,2,n-2) if ( c[i]&&c[n-i] ) {
        printf("%d %d\n",i,n-i);
        return 0;
    }
    return 0;
}