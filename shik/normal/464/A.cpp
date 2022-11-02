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
int n,m;
char s[N],t[N];

bool dfs( int p, bool flg ) {
    //printf("%d, %d: %s\n",p,(int)flg,t);
    if ( p==n ) return flg;
    char st=flg?'a':s[p];
    char ed='a'+m-1;
    REP1(i,st,ed) {
        t[p]=i;
        if ( p>=1 && t[p]==t[p-1] ) continue;
        if ( p>=2 && t[p]==t[p-2] ) continue;
        if ( dfs(p+1,flg||(i>s[p])) ) return 1;
    }
    return 0;
}

int main() {
    RI(n,m);
    scanf("%s",s);
    if ( dfs(0,0) ) puts(t);
    else puts("NO");
    return 0;
}