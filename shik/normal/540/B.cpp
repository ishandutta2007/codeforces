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

#define N 2010
int a[N];
int main() {
    int n,k,p,x,y;
    RI(n,k,p,x,y);
    REP(i,k) RI(a[i]);
    int c=0;
    REP(i,k) c+=(a[i]>=y);
    int m=k;
    while ( c<(n+1)/2 ) a[m++]=y,c++;
    while ( m<n ) a[m++]=1;
    if ( m>n ) puts("-1");
    else {
        int s=0;
        REP(i,n) s+=a[i];
        if ( s>x ) puts("-1");
        else {
            for ( int i=k; i<n; i++ ) printf("%d%c",a[i],i+1==n?'\n':' ');
        }
    }
    return 0;
}