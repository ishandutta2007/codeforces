// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
#define ALL(x) begin(x),end(x)
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

#define N 300010
int n,p,sdeg[N];
vector<int> e[N];
map<int,int> cnt[N];
int main() {
    RI(n,p);
    REP(i,n) {
        int a,b;
        RI(a,b);
        e[a].PB(b);
        e[b].PB(a);
        cnt[a][b]++;
        cnt[b][a]++;
    }
    REP1(i,1,n) sort(ALL(e[i]));
    REP1(i,1,n) sdeg[SZ(e[i])]++;
    for ( int i=n-1; i>=0; i-- ) sdeg[i]+=sdeg[i+1];
    LL ans=0;
    REP1(i,1,n) {
        int di=SZ(e[i]);
        if ( di>=p ) {
            ans+=n-1;
            continue;
        }
        int ldj=p-di;
        int now=sdeg[ldj];
        if ( di>=ldj ) now--; // exclude (i, i)
        set<int> s(ALL(e[i]));
        for ( auto j : s ) {
            int dj=SZ(e[j]);
            if ( dj<ldj ) continue;
            int sd=di+dj-cnt[i][j];
            if ( sd<p ) now--;
        }
        ans+=now;
    }
    ans/=2;
    cout<<ans<<endl;
    return 0;
}