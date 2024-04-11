#include <cstdio>

int n, x, c[7];

int main() {
    scanf( "%d", &n );
    for ( int i=0; i<n; i++ ) { scanf( "%d", &x ); c[x]++; }
    int ans = c[4];
    int k = c[3];
    ans += k;
    c[1] -= k;
    if ( c[1] < 0 ) c[1] = 0;
    k = c[2] / 2;
    ans += k;
    c[2] -= 2 * k;
    if ( c[2] > 0 ) {
        c[2] = 0;
        ans++;
        c[1] -= 2;
        if ( c[1] < 0 ) c[1] = 0;
    }
    ans += ( c[1] + 3 ) / 4;
    printf( "%d\n", ans );
    return 0;
}