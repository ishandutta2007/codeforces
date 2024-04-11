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
int n,m,a[N],b[N];
LL sa[N],sb[N];
int main() {
    RI(n,m);
    REP(i,n) RI(a[i]);
    REP(i,m) RI(b[i]);
    sort(a,a+n);
    sort(b,b+m);
    REP(i,n) sa[i+1]=sa[i]+a[i];
    REP(i,m) sb[i+1]=sb[i]+b[i];
    LL ans=1e18;
    auto upd=[&]( int x ) {
        int pa=lower_bound(a,a+n,x)-a;
        int pb=lower_bound(b,b+m,x)-b;
        LL da=1LL*pa*x-sa[pa];
        LL db=sb[m]-sb[pb]-1LL*(m-pb)*x;
        ans=min(ans,da+db);
    };
    REP(i,n) upd(a[i]);
    REP(i,m) upd(b[i]);
    cout<<ans<<endl;
    return 0;
}