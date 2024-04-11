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
#define M 110
int n,m,w;
char s[N][M];
void input() {
    int r,c;
    RI(r,c,n,w);
    m=r*c;
    REP1(i,1,n) REP(j,r) scanf("%s",s[i]+j*c);
}

int d[N][N];
void build() {
    REP1(i,1,n) d[0][i]=d[i][0]=m;
    REP1(i,1,n) REP1(j,1,i-1) {
        int c=0;
        REP(k,m) c+=(s[i][k]!=s[j][k]);
        d[i][j]=d[j][i]=c*w;
    }
}

int dis[N],pre[N];
bool vis[N];
void solve() {
    REP1(i,1,n) {
        dis[i]=d[0][i];
        pre[i]=0;
    }
    int ans=0;
    vector<PII> sol;
    REP(i,n) {
        int w=0;
        REP1(j,1,n) if ( !vis[j] && (w==0 || dis[j]<dis[w]) ) w=j;
        assert(w!=0);
        vis[w]=1;
        ans+=dis[w];
        sol.PB(MP(w,pre[w]));
        REP1(j,1,n) if ( !vis[j] && d[w][j]<dis[j] ) {
            dis[j]=d[w][j];
            pre[j]=w;
        }
    }
    printf("%d\n",ans);
    assert(SZ(sol)==n);
    REP(i,n) printf("%d %d\n",sol[i].first,sol[i].second);
}

int main() {
    input();
    build();
    solve();
    return 0;
}