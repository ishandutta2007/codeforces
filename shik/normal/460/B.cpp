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

int ds( LL x ) {
    int s=0;
    while ( x ) {
        s+=x%10;
        x/=10;
    }
    return s;
}

int main() {
    int a,b,c;
    RI(a,b,c);
    set<int> sol;
    REP1(i,1,100) {
        LL x=b;
        REP(j,a) x*=i;
        x+=c;
        if ( ds(x)==i && x>0 && x<1000000000 ) sol.insert(x);
    }
    int n=SZ(sol);
    vector<int> v(ALL(sol));
    printf("%d\n",n);
    REP(i,n) printf("%d%c",v[i],i+1==n?'\n':' ');
    return 0;
}