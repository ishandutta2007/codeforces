// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
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

#define N 100010
int c[N],cn;
VI e[N];
void dfs( int p, int f, int lv ) {
    if ( lv>0 ) c[cn++]=lv;
    FOR(it,e[p]) if ( *it!=f ) dfs(*it,p,lv+1);
}

int n,k,p;
bool chk( int m ) {
    LL now=0;
    REP1(i,1,m-1) if ( c[i]!=c[i-1] ) now+=i;
    if ( now<=p ) return 1;
    REP1(i,m,cn-1) {
        if ( c[i]!=c[i-1] ) now+=m;
        now-=c[i]-c[i-m];
        if ( now<=p ) return 1;
    }
    return 0;
}

int main() {
    RI(n,k,p);
    REP(i,n-1) {
        int a,b;
        RI(a,b);
        e[a].PB(b);
        e[b].PB(a);
    }
    dfs(1,0,0);
    sort(c,c+cn);
    int l=1,r=min(k,n-1);
    while ( l!=r ) {
        int m=(l+r+1)/2;
        if ( chk(m) ) l=m;
        else r=m-1;
    }
    printf("%d\n",l);
    return 0;
}