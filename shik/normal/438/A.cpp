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

#define N 1010
int n,m,v[N],e[N][N];
bool vis[N];
int main() {
    RI(n,m);
    REP1(i,1,n) RI(v[i]);
    REP(i,m) {
        int x,y;
        RI(x,y);
        e[x][y]=e[y][x]=1;
    }
    LL ans=0;
    REP(_,n) {
        int w=0;
        REP1(i,1,n) if ( !vis[i] && (w==0 || v[i]>v[w]) ) w=i;
        assert(w != 0);
        vis[w]=1;
        REP1(i,1,n) if ( !vis[i] && e[w][i] ) ans+=v[i];
    }
    cout<<ans<<endl;
    return 0;
}