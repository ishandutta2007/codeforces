// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int c[N],has[N];
set<int> q[N];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for ( int i=1; i<=n; i++ ) scanf("%d",c+i);
    for ( int i=1; i<=n; i++ ) has[c[i]]=1;
    while ( m-- ) {
        int a,b;
        scanf("%d%d",&a,&b);
        if ( c[a]==c[b] ) continue;
        q[c[a]].insert(c[b]);
        q[c[b]].insert(c[a]);
    }
    int ans=0;
    for ( int i=0; i<N; i++ ) if ( has[i] && (ans==0 || q[i].size()>q[ans].size()) ) ans=i;
    printf("%d\n",ans);
    return 0;
}