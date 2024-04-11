// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 110
struct DJS {
    int fa[N];
    void init( int n ) { for ( int i=1; i<=n; i++ ) fa[i]=i; }
    int Find( int x ) { return fa[x]==x?x:fa[x]=Find(fa[x]); }
    void Union( int a, int b ) { fa[Find(a)]=Find(b); }
} djs;
vector<int> v[N];
int main()
{
    int n,m,flg=0;
    scanf("%d%d",&n,&m);
    for ( int i=1; i<=n; i++ ) {
        int k,x;
        scanf("%d",&k);
        while ( k-- ) {
            flg=1;
            scanf("%d",&x);
            v[x].push_back(i);
        }
    }
    djs.init(n);
    for ( int i=1; i<=m; i++ ) FOR(it,v[i]) djs.Union(v[i][0],*it);
    int ans=0;
    for ( int i=1; i<=n; i++ ) if ( djs.Find(i)==i ) ans++;
    ans-=flg;
    printf("%d\n",ans);
    return 0;
}