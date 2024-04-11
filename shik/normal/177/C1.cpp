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
int sz[N];
bool bye[N];
int main()
{
    int n,k,m;
    scanf("%d%d",&n,&k);
    djs.init(n);
    while ( k-- ) {
        int a,b;
        scanf("%d%d",&a,&b);
        djs.Union(a,b);
    }
    scanf("%d",&m);
    while ( m-- ) {
        int a,b;
        scanf("%d%d",&a,&b);
        if ( djs.Find(a)!=djs.Find(b) ) continue;
        bye[djs.Find(a)]=1;
    }
    for ( int i=1; i<=n; i++ ) sz[djs.Find(i)]++;
    int ans=0;
    for ( int i=1; i<=n; i++ ) if ( i==djs.Find(i) && !bye[i] ) ans=max(ans,sz[i]);
    printf("%d\n",ans);
    return 0;
}