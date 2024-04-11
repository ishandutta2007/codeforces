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

#define N 22
int n,m;
char r[N],c[N];
bool vis[N][N];

bool out( int x, int y ) {
    return x<0 || x>=n || y<0 || y>=m;
}

int main() {
    RI(n,m);
    REP(i,n) scanf(" %c",r+i);
    REP(i,m) scanf(" %c",c+i);
    bool good=1;
    REP(i,n) REP(j,m) {
        memset(vis,0,sizeof(vis));
        queue<int> q;
        auto push=[&]( int x, int y ) {
            if ( out(x,y) ) return;
            if ( vis[x][y] ) return;
            vis[x][y]=1;
            q.push(x);
            q.push(y);
        };
        auto pop=[&]( int &x, int &y ) {
            x=q.front(); q.pop();
            y=q.front(); q.pop();
        };
        push(i,j);
        while ( !q.empty() ) {
            int x,y; pop(x,y);
            if ( r[x]=='<' ) push(x,y-1);
            else push(x,y+1);
            if ( c[y]=='^' ) push(x-1,y);
            else push(x+1,y);
        }
        REP(i,n) REP(j,m) if ( !vis[i][j] ) good=0;
    }
    puts(good?"YES":"NO");
    return 0;
}