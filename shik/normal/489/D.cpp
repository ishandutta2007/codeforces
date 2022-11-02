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

#define N 3010
int n,m;
VI e1[N],e2[N];
bool vis[N];
int main() {
    RI(n,m);
    REP(i,m) {
        int a,b;
        RI(a,b);
        e1[a].PB(b);
        e2[b].PB(a);
    }
    LL ans=0;
    REP1(i,1,n) {
        FOR(it,e1[i]) vis[*it]=1;
        REP1(j,1,n) if ( i!=j ) {
            int c=0;
            FOR(jt,e2[j]) if ( vis[*jt] ) c++;
            ans+=c*(c-1)/2;
        }
        FOR(it,e1[i]) vis[*it]=0;
    }
    cout<<ans<<endl;
    return 0;
}