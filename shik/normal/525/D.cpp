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

#define N 2020

int n,m;
char s[N][N];

queue<int> q;
const int dx[]={1,0,-1,0,1};
const int dy[]={0,1,0,-1,0};

int f( int a, int b ) {
    return a ? a : b;
}

void chk( int x, int y ) {
    if ( s[x][y]!='*' ) return;
    REP(i,4) {
        int x1=x+dx[i];
        int y1=y+dy[i];
        int x2=x+dx[i+1];
        int y2=y+dy[i+1];
        int x3=x+f(dx[i],dx[i+1]);
        int y3=y+f(dy[i],dy[i+1]);
        if ( s[x1][y1]=='.' && s[x2][y2]=='.' && s[x3][y3]=='.' ) {
            s[x][y]='.';
            REP1(xx,x-1,x+1) REP1(yy,y-1,y+1) chk(xx,yy);
            return;
        }
    }
}

int main() {
    RI(n,m);
    REP1(i,1,n) scanf("%s",s[i]+1);
    REP1(i,1,n) REP1(j,1,m) chk(i,j);
    REP1(i,1,n) puts(s[i]+1);
    return 0;
}