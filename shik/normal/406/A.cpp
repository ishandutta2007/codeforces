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

#define N 1010
int n,a[N][N],b[N];
int main() {
    RI(n);
    REP1(i,1,n) REP1(j,1,n) RI(a[i][j]);
    REP1(i,1,n) b[i]=a[i][i];
    int s=0;
    REP1(i,1,n) s^=b[i];
    int q;
    RI(q);
    while ( q-- ) {
        int op;
        RI(op);
        if ( op==1 || op==2 ) {
            scanf("%*d");
            s^=1;
        } else if ( op==3 ) {
            printf("%d",s);
        } else puts("QQ");
    }
    puts("");
    return 0;
}