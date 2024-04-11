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

#define N 2014

int n,m,sol[N];
char s[N][N];

bool in( int x, int y ) {
    return 1<=x && x<=n && 1<=y && y<=m;
}

int main() {
    scanf("%d%d%*d",&n,&m);
    REP1(i,1,n) scanf("%s",s[i]+1);
    REP1(j,1,m) {
        int c=0;
        REP1(i,1,n) {
            int t=i-1;
            if ( in(i,j-t) && s[i][j-t]=='R' ) c++;
            if ( in(i,j+t) && s[i][j+t]=='L' ) c++;
            if ( in(i+t,j) && s[i+t][j]=='U' ) c++;
        }
        sol[j]=c;
    }
    REP1(i,1,m) printf("%d%c",sol[i],i==m?'\n':' ');
    return 0;
}