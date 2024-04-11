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

int solve( int n, int a[], int b[] ) {
    sort(a,a+n);
    sort(b,b+n-1);
    REP(i,n-1) if ( a[i]!=b[i] ) return a[i];
    return a[n-1];
}

int n,a[N],b[N],c[N];
int main() {
    RI(n);
    REP(i,n) RI(a[i]);
    REP(i,n-1) RI(b[i]);
    REP(i,n-2) RI(c[i]);
    printf("%d\n%d\n",solve(n,a,b),solve(n-1,b,c));
    return 0;
}