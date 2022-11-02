#include <cstdio>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )

pair<int,int> a[8010];
int f[4010][4010];
int n, k;

inline int when(int finish, pair<int,int>& task) {
    if ( task.first-1 > finish ) finish = task.first - 1;
    return finish + task.second;
}

int main() {
    scanf( "%d %d", &n, &k );
    forn( i, n ) scanf( "%d %d", &a[i].first, &a[i].second );
    int nn = n;
    forn( i, k+2 ) a[nn++] = make_pair( 86401, 1 );
    sort( a, a+nn );
    memset( f, 0x3f3f3f3f, sizeof(f) );
    f[0][0] = 0;
    int ans = a[k].first - 1;
    for ( int i=1; i<=n; i++ )
        for ( int j=0; j<=k; j++ ) {
            if ( j > i ) break;
            f[i][j] = when( f[i-1][j], a[i-1] );
            if ( j > 0 ) f[i][j] = min( f[i][j], f[i-1][j-1] );
            if ( a[i+k-j].first - f[i][j] - 1 > ans )
                ans = a[i+k-j].first - f[i][j] - 1;
        }
    printf( "%d\n", ans );
    return 0;
}