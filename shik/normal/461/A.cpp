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

#define N 300010
int n,a[N];
int main() {
    RI(n);
    REP(i,n) RI(a[i]);
    sort(a,a+n);
    if ( n==1 ) printf("%d\n",a[0]);
    else {
        LL ans=0;
        REP(i,n) ans+=a[i]*(i+2LL);
        ans-=a[n-1];
        cout<<ans<<endl;
    }
    return 0;
}