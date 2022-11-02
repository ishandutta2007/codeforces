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

#define N 5000010
int cnt[N];
int main() {
    for ( int i=2; i<N; i++ ) if ( !cnt[i] ) {
        int p=1;
        while ( p<=N/i ) {
            p*=i;
            for ( int j=p; j<N; j+=p ) cnt[j]++;
        }
    }
    REP1(i,1,N-1) cnt[i]+=cnt[i-1];
    int t;
    RI(t);
    while ( t-- ) {
        int a,b;
        RI(a,b);
        int ans=cnt[a]-cnt[b];
        printf("%d\n",ans);
    }
    return 0;
}