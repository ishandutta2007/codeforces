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

#define N 514
int n,m;
char s[N][N];
bool vis[N][N];

const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};

int main() {
    RI(n,m);
    REP1(i,1,n) scanf("%s",s[i]+1);
    int sx,sy,ex,ey;
    RI(sx,sy,ex,ey);
    queue<int> q;
    vis[sx][sy]=1;
    q.push(sx);
    q.push(sy);
    while ( !q.empty() ) {
        int x=q.front(); q.pop();
        int y=q.front(); q.pop();
        REP(i,4) {
            int xx=x+dx[i];
            int yy=y+dy[i];
            if ( s[xx][yy]=='.' && !vis[xx][yy] ) {
                vis[xx][yy]=1;
                q.push(xx);
                q.push(yy);
            }
        }
    }
    s[sx][sy]='.';
    bool good=0;
    int cnt=0;
    REP(i,4) {
        int xx=ex+dx[i];
        int yy=ey+dy[i];
        if ( vis[xx][yy] ) good=1;
        cnt+=(s[xx][yy]=='.');
    }
    if ( s[ex][ey]=='.' && (sx!=ex || sy!=ey) ) good&=(cnt>=2);
    puts(good?"YES":"NO");
    return 0;
}