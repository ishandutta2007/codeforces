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

#define N 5010
int n,a[N];

int go( int l, int r ) {
    if ( l>r ) return 0;
    int ret=r-l+1;
    int m=min_element(a+l,a+r+1)-a;
    int h=a[m];
    REP1(i,l,r) a[i]-=h;
    ret=min(ret,go(l,m-1)+go(m+1,r)+h);
    return ret;
}

int main() {
    RI(n);
    REP1(i,1,n) RI(a[i]);
    int ans=go(1,n);
    printf("%d\n",ans);
    return 0;
}