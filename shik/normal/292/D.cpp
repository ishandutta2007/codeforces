// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 514
#define M 20010
struct DJS {
    int fa[N];
    void init( int n ) { for ( int i=1; i<=n; i++ ) fa[i]=i; }
    int Find( int x ) { return fa[x]==x?x:fa[x]=Find(fa[x]); }
    void Union( int a, int b ) { fa[Find(a)]=Find(b); }
} dl[M],dr[M],djs;
struct E {
    int a,b;
    void read() { scanf("%d%d",&a,&b); }
} e[M];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for ( int i=1; i<=m; i++ ) e[i].read();
    dl[0].init(n);
    for ( int i=1; i<=m; i++ ) {
        for ( int j=1; j<=n; j++ ) dl[i].fa[j]=dl[i-1].fa[j];
        dl[i].Union(e[i].a,e[i].b);
    }
    dr[m+1].init(n);
    for ( int i=m; i>=1; i-- ) {
        for ( int j=1; j<=n; j++ ) dr[i].fa[j]=dr[i+1].fa[j];
        dr[i].Union(e[i].a,e[i].b);
    }
    int q,l,r;
    scanf("%d",&q);
    while ( q-- ) {
        scanf("%d%d",&l,&r);
        djs.init(n);
        for ( int i=1; i<=n; i++ ) djs.Union(i,dl[l-1].Find(i));
        for ( int i=1; i<=n; i++ ) djs.Union(i,dr[r+1].Find(i));
        int ans=0;
        for ( int i=1; i<=n; i++ ) if ( djs.Find(i)==i ) ans++;
        printf("%d\n",ans);
    }
    return 0;
}