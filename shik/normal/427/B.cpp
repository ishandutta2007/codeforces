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

#define N 200010
int n,t,c,a[N],sa[N];
int main() {
    RI(n,t,c);
    REP1(i,1,n) RI(a[i]);
    REP1(i,1,n) sa[i]=sa[i-1]+(a[i]<=t);
    int ans=0;
    REP1(i,c,n) ans+=(sa[i]-sa[i-c]==c);
    printf("%d\n",ans);
    return 0;
}