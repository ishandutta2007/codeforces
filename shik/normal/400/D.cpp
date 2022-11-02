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
#define K 514
struct DJS {
    int fa[N];
    void init( int n ) { REP1(i,1,n) fa[i]=i; }
    int Find( int x ) { return x==fa[x]?x:fa[x]=Find(fa[x]); }
    void Union( int a, int b ) { fa[Find(a)]=Find(b); }
} djs;

int n,m,k,c[N],type[N],w[K][K];
int main() {
    RI(n,m,k);
    REP1(i,1,k) RI(c[i]);
    int s=0;
    REP1(i,1,k) REP(j,c[i]) type[++s]=i;
    djs.init(n);
    REP1(i,1,k) REP1(j,1,k) if ( i!=j ) w[i][j]=1e9;
    REP(i,m) {
        int a,b,co;
        RI(a,b,co);
        if ( co==0 ) djs.Union(a,b);
        int ta=type[a];
        int tb=type[b];
        w[ta][tb]=min(w[ta][tb],co);
        w[tb][ta]=min(w[tb][ta],co);
    }
    REP1(i,1,n) if ( i==1 || type[i]!=type[i-1] ) {
        for ( int j=i; j<=n && type[j]==type[i]; j++ )
            if ( djs.Find(j)!=djs.Find(i) ) {
                puts("No");
                return 0;
            }
    }
    REP1(x,1,k) REP1(i,1,k) REP1(j,1,k) w[i][j]=min(w[i][j],w[i][x]+w[x][j]);
    puts("Yes");
    REP1(i,1,k) REP1(j,1,k) printf("%d%c",w[i][j]==1e9?-1:w[i][j],j==k?'\n':' ');
    return 0;
}