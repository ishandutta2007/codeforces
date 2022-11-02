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

vector<LL> fac,sol;

int take( LL x, LL k, int n ) {
    if ( n==0 ) return 0;
    if ( x==1 ) {
        sol.PB(1);
        return 1;
    }
    if ( k==0 ) {
        sol.PB(x);
        return 1;
    }
    int ret=0;
    for ( auto i : fac ) {
        if ( i>x ) break;
        if ( x%i!=0 ) continue;
        ret+=take(i,k-1,n-ret);
        if ( ret==n ) return ret;
    }
    return ret;
}

LL x,k;
int main() {
    ios_base::sync_with_stdio(0);
    cin>>x>>k;
    for ( LL i=1; i*i<=x; i++ ) if ( x%i==0 ) {
        fac.PB(i);
        if ( i!=x/i ) fac.PB(x/i);
    }
    sort(ALL(fac));
    take(x,k,100000);
    REP(i,SZ(sol)) cout<<sol[i]<<(i+1==SZ(sol)?'\n':' ');
    return 0;
}