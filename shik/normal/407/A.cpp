// shik {{{
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(c) begin(c),end(c)
#define REP(i,n) for ( int i=0; i<(int)(n); i++ )
#define REP1(i,a,b) for ( int i=(int)(a); i<=(int)(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
// }}}

int main() {
    int a,b;
    RI(a,b);
    REP1(i,1,1000) REP1(j,1,1000) {
        if ( i*i+j*j!=a*a ) continue;
        int g=__gcd(i,j);
        int x=-j/g;
        int y=i/g;
        int t=1;
        while ( t*t*(x*x+y*y)<b*b ) t++;
        x*=t;
        y*=t;
        if ( x*x+y*y!=b*b ) continue;
        if ( y==j ) continue;
        puts("YES");
        printf("%d %d\n",0,0);
        printf("%d %d\n",i,j);
        printf("%d %d\n",x,y);
        return 0;
    }
    puts("NO");
    return 0;
}