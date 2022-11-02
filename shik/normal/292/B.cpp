// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 100010
struct DJS {
    int fa[N];
    void init( int n ) { for ( int i=1; i<=n; i++ ) fa[i]=i; }
    int Find( int x ) { return fa[x]==x?x:fa[x]=Find(fa[x]); }
    void Union( int a, int b ) { fa[Find(a)]=Find(b); }
} djs;
int n,m;
vector<int> e[N];
bool bus() {
    if ( m!=n-1 ) return 0;
    for ( int i=1; i<=n; i++ ) if ( SZ(e[i])>2 ) return 0;
    return 1;
}
bool ring() {
    if ( m!=n ) return 0;
    for ( int i=1; i<=n; i++ ) if ( SZ(e[i])!=2 ) return 0;
    return 1;
}
bool star() {
    if ( m!=n-1 ) return 0;
    for ( int i=1; i<=n; i++ ) if ( SZ(e[i])!=1 && SZ(e[i])!=n-1 ) return 0;
    return 1;
}
int main()
{
    scanf("%d%d",&n,&m);
    djs.init(n);
    for ( int i=0; i<m; i++ ) {
        int a,b;
        scanf("%d%d",&a,&b);
        e[a].push_back(b);
        e[b].push_back(a);
        djs.Union(a,b);
    }
    bool conn=1;
    for ( int i=1; i<=n; i++ ) if ( djs.Find(i)!=djs.Find(1) ) conn=0;
    if ( !conn ) puts("unknown topology");
    else if ( bus() ) puts("bus topology");
    else if ( ring() ) puts("ring topology");
    else if ( star() ) puts("star topology");
    else puts("unknown topology");
    return 0;
}