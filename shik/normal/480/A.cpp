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
int n;
PII x[N];
int main() {
    RI(n);
    REP(i,n) RI(x[i].first,x[i].second);
    sort(x,x+n);
    int t=0;
    REP(i,n) {
        if ( x[i].second>=t ) t=x[i].second;
        else t=x[i].first;
    }
    printf("%d\n",t);
    return 0;
}