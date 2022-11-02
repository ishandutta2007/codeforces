// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
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

#define N 1000010
int n,p[N],s[N];
int main() {
    RI(n);
    REP1(i,1,n) RI(p[i]);
    int ans=0;
    REP1(i,1,n) ans^=p[i];
    REP1(i,1,n) s[i]=s[i-1]^i;
    REP1(i,1,n) {
        int m=n%(2*i);
        if ( m<i ) {
            ans^=s[m];
        } else {
            ans^=s[i-1]^s[m-i];
        }
    }
    printf("%d\n",ans);
    return 0;
}