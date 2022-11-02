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
bool pri[N],vis[N];
vector<PII> sol;

void push( int a, int b ) {
    vis[a]=vis[b]=1;
    sol.PB(MP(a,b));
}

int main() {
    for ( int i=2; i<N; i++ ) for ( int j=i+i; j<N; j+=i ) pri[j]=1;
    int n;
    RI(n);
    for ( int i=n; i>=2; i-- ) if ( !pri[i] ) {
        vector<int> v;
        for ( int j=i; j<=n; j+=i ) if ( !vis[j] ) v.PB(j);
        if ( SZ(v)<=1 ) continue;
        if ( SZ(v)%2==0 ) {
            for ( int j=0; j<SZ(v); j+=2 ) push(v[j],v[j+1]);
        } else {
            push(v[0],v[2]);
            for ( int j=3; j<SZ(v); j+=2 ) push(v[j],v[j+1]);
        }
    }
    printf("%d\n",SZ(sol));
    FOR(it,sol) printf("%d %d\n",it->first,it->second);
    return 0;
}