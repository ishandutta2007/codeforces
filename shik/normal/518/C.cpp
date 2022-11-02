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
int a[N],b[N],ia[N];
int main() {
    int n,m,k;
    RI(n,m,k);
    REP(i,n) RI(a[i]);
    REP(i,m) RI(b[i]);
    REP(i,n) ia[--a[i]]=i;
    LL ans=m;
    REP(i,m) {
        b[i]--;
        int pos=ia[b[i]];
        ans+=pos/k;
        if ( pos==0 ) continue;
        swap(a[pos],a[pos-1]);
        ia[a[pos]]=pos;
        ia[a[pos-1]]=pos-1;
    }
    printf("%lld\n",ans);
    return 0;
}