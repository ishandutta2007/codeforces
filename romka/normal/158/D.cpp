#include <cstdio>
#include <vector>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back

int n, a[20010];

int main() {
    scanf( "%d", &n );
    forn( i, n ) scanf( "%d", &a[i] );
    int ans = -1010 * n;
    for ( int v = 3; v <= n; v++ )
        if ( n % v == 0 ) {
            int skip = n / v;
            vector<int> ind;
            for ( int i = 0; i < n; i += skip )
                ind.pb( i );
            forn( q, skip ) {
                int sum = 0;
                forn( i, ind.size() ) {
                    sum += a[ ind[i] ];
                    ind[i]++;
                }
                if ( sum > ans ) ans = sum;
            }
        }
    printf( "%d\n", ans );
    return 0;
}