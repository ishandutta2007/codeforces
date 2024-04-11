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
    int Find( int x ) { return x==fa[x]?x:fa[x]=Find(fa[x]); }
    void Union( int a, int b ) { fa[Find(a)]=Find(b); }
} djs;
int main()
{
    int n,x[110],y[110];
    scanf("%d",&n);
    for ( int i=1; i<=n; i++ ) scanf("%d%d",x+i,y+i);
    djs.init(n);
    int sx[1010]={},sy[1010]={};
    for ( int i=1; i<=n; i++ ) {
        if ( sx[x[i]] ) djs.Union(i,sx[x[i]]);
        if ( sy[y[i]] ) djs.Union(i,sy[y[i]]);
        sx[x[i]]=i; sy[y[i]]=i;
    }
    int cnt=0;
    for ( int i=1; i<=n; i++ ) if ( djs.Find(i)==i ) cnt++;
    printf("%d\n",cnt-1);
    return 0;
}