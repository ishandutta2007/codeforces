// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
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
struct C {
    int x,y,k;
    void read() {
        RI(x,y,k);
    }
} c[N];

int main() {
    int n,s;
    RI(n,s);
    REP(i,n) c[i].read();
    sort(c,c+n,[](C a, C b) { return a.x*a.x+a.y*a.y<b.x*b.x+b.y*b.y; });
    int i=0;
    while ( i<n ) {
        s+=c[i].k;
        if ( s>=1e6 ) {
            printf("%.9f\n",sqrt(c[i].x*c[i].x+c[i].y*c[i].y));
            return 0;
        }
        i++;
    }
    puts("-1");
    return 0;
}