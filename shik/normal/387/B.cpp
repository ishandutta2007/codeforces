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

#define N 3010
int a[N],b[N];
int main() {
    int n,m;
    RI(n,m);
    REP(i,n) RI(a[i]);
    REP(i,m) RI(b[i]);
    sort(a,a+n);
    sort(b,b+m);
    int ans=0;
    for ( int i=0,j=0; i<n; i++ ) {
        while ( j<m && b[j]<a[i] ) j++;
        if ( j<m ) j++;
        else ans++;
    }
    printf("%d\n",ans);
    return 0;
}