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

int main() {
    vector<int> l{4,7};
    for ( int i=0; i<SZ(l); i++ ) if ( l[i]<=1e8 )
        for ( int j : {10 * l[i] + 4, 10 * l[i] + 7} )
            l.push_back(j);
    int n;
    RI(n);
    int idx=find(ALL(l),n)-l.begin();
    printf("%d\n",idx+1);
    return 0;
}