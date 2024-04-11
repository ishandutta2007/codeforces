// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
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

#define N 100010
int a[N];
int main() {
    int n,k;
    RI(n,k);
    if ( k<n/2 ) {
        puts("-1");
        return 0;
    }
    if ( n==1 ) {
        if ( k!=0 ) puts("-1");
        else puts("1");
        return 0;
    }
    a[0]=k-n/2+1;
    a[1]=2*a[0];
    REP1(i,2,n-1) a[i]=1e9-i;
    REP(i,n) printf("%d%c",a[i],i+1==n?'\n':' ');
    return 0;
}