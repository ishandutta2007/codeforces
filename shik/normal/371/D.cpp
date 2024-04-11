#include <cstdio>
#include <algorithm>
using namespace std;

#define N 200010

struct DisjointSet {
    int fa[N];
    void init( int n ) {
        for ( int i=1; i<=n; i++ ) fa[i] = i;
    }
    int Find( int x ) {
        return x == fa[x] ? x : fa[x] = Find(fa[x]);
    }
    void Union( int a, int b ) {
        fa[Find(a)] = Find(b);
    }
} djs;

int n, m, a[N], b[N];

int main() {
    scanf("%d", &n);
    for ( int i=1; i<=n; i++ ) scanf("%d", a+i);
    djs.init(n+1);
    scanf("%d", &m);
    while ( m-- ) {
        int op, p, x, k;
        scanf("%d", &op);
        if ( op==1 ) {
            scanf("%d%d", &p, &x);
            do {
                p = djs.Find(p);
                if ( p>n ) break; // overflow to floor
                int y = min(x, a[p] - b[p]);
                b[p] += y;
                x -= y;
                if ( a[p]==b[p] ) djs.Union(p, p+1);
            } while ( x>0 );
        } else {
            scanf("%d", &k);
            printf("%d\n", b[k]);
        }
    }
    return 0;
}