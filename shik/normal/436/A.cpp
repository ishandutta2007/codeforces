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
int n,x,t[N],h[N],m[N];

int solve() {
    bool vis[N]={};
    int ret=0,tt=0,s=x;
    while ( 1 ) {
        int w=-1;
        REP(i,n) if ( !vis[i] && t[i]==tt && h[i]<=s && (w==-1 || m[i]>m[w]) ) w=i;
        if ( w==-1 ) break;
        ret++;
        vis[w]=1;
        s+=m[w];
        tt^=1;
    }
    return ret;
}

int main() {
    RI(n,x);
    REP(i,n) RI(t[i],h[i],m[i]);
    int ans=solve();
    REP(i,n) t[i]^=1;
    ans=max(ans,solve());
    printf("%d\n",ans);
    return 0;
}