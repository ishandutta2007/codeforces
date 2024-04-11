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

#define N 25
void solve( int n, int p ) {
    bool e[N][N]={};
    REP1(i,1,n) REP1(j,1,2) {
        int to=i+j;
        if ( to>n ) to-=n;
        e[i][to]=e[to][i]=1;
    }
    while ( p-- ) {
        REP1(i,1,n) REP1(j,1,n) if ( i!=j && !e[i][j] ) {
            e[i][j]=e[j][i]=1;
            i=j=n+1;
        }
    }
    REP1(i,1,n) REP1(j,i+1,n) if ( e[i][j] ) printf("%d %d\n",i,j);
}

int main() {
    int t;
    RI(t);
    while ( t-- ) {
        int n,p;
        RI(n,p);
        solve(n,p);
    }
    return 0;
}