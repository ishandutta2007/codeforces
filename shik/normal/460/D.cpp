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
    LL l,r,k;
    cin>>l>>r>>k;
    vector<LL> sol={l};
    auto meow=[]( vector<LL> v ) {
        LL x=0;
        FOR(it,v) x^=*it;
        return x;
    };
    auto shik=[&]( vector<LL> v ) {
        sort(ALL(v));
        v.erase(unique(ALL(v)),v.end());
        if ( v.empty() || SZ(v)>k ) return;
        FOR(it,v) if ( *it<l || *it>r ) return;
        LL x=meow(sol);
        LL y=meow(v);
        if ( y<x ) sol=v;
    };
    int n=min(r-l+1,10LL);
    REP(i,1<<n) {
        vector<LL> v;
        REP(j,n) if ( (i>>j)&1 ) v.PB(l+j);
        shik(v);
        LL x=meow(v);
        v.PB(x);
        shik(v);
    }
    if ( k>=3 ) {
        LL x=l;
        while ( (x&-x)!=x ) x^=x&-x;
        shik(vector<LL>{l,3*x,l^(3*x)});
    }
    cout<<meow(sol)<<endl;
    cout<<SZ(sol)<<endl;
    int sz=SZ(sol);
    REP(i,sz) cout<<sol[i]<<(i+1==sz?'\n':' ');
    return 0;
}