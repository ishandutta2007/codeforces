#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <algorithm>
using namespace std;

struct p {
    int l, r, u, d;
    p () {
        l = -1; u = -1;
        r = 5042; d = 5042;
    }
};
vector < p > a[5042];
int n, m, ansC, ansL;
char input[5042][5042];

void rem ( int i, int j ) {
    if ( a[i][j].l != -1 ) {
        a[i][ a[i][j].l ].r = a[i][j].r;
    }
    if ( a[i][j].r < m ) {
        a[i][ a[i][j].r ].l = a[i][j].l;
    }
    if ( a[i][j].u != -1 ) {
        a[ a[i][j].u ][j].d = a[i][j].d;
    }
    if ( a[i][j].d < n ) {
        a[ a[i][j].d ][j].u = a[i][j].u;
    }
}
void add ( int i, int j, p crr ) {
    if ( crr.l != -1 ) {
        a[i][ crr.l ].r = j;
    }
    if ( crr.r < m ) {
        a[i][ crr.r ].l = j;
    }
    if ( crr.u != -1 ) {
        a[ crr.u ][j].d = i;
    }
    if ( crr.d < n ) {
        a[ crr.d ][j].u = i;
    }
}

void pre () {
    for ( int y = 0 ; y < n ; y ++ ) {
        int x = 0;
        for ( ; x < m && input[y][x] == '.' ; x ++ ){}
        for ( ; x < m ; ) {
            int x2 = x+1;
            for ( ; x2 < m && input[y][x2] == '.' ; x2 ++ ) {}
            if ( x2 != m ) {
                a[y][x].r = x2;
                a[y][x2].l = x;
            }
            x = x2;
        }
    }

    for ( int x = 0 ; x < m ; x ++ ) {
        int y = 0;
        for ( ; y < n && input[y][x] == '.' ; y ++ ) {}
        for ( ; y < n ; ) {
            int y2 = y+1;
            for ( ; y2 < n && input[y2][x] == '.' ; y2 ++ ) {}
            if ( y2 != n ) {
                a[y][x].d = y2;
                a[y2][x].u = y;
            }
            y = y2;
        }
    }
}

int dfs ( int y, int x ) {
   // cout << y << " " << x << "\n";
    if ( y == -1 || x == -1 || x >= m || y >= n ) { return 0; }
    p crr = a[y][x];
    rem ( y, x );
    int ret;
    if ( input[y][x] == 'U' ) {
        ret = dfs( crr.u, x );
    }
    if ( input[y][x] == 'D' ) {
        ret = dfs( crr.d, x );
    }
    if ( input[y][x] == 'L' ) {
        ret = dfs( y, crr.l );
    }
    if ( input[y][x] == 'R' ) {
        ret = dfs( y, crr.r );
    }
    add ( y, x, crr );
    //cout << x << " , " << y  << " " << input[y][x] << " : " << ret << "\n";
    return ret+1;
}

int main () {
    cin >> n >> m;
    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> input[i];
        for ( int j = 0 ; j <= m ; j ++ ) {
            a[i].push_back( p() );
        }
    }
    pre();

    for ( int k = 0 ; k < 1 ; k ++ ) {
        ansL = 0; ansC = 0;

        for ( int i = 0 ; i < n ; i ++ ) {
            for ( int j = 0 ; j < m ; j ++ ) {
                if ( input[i][j] == '.' ) { continue; }
                int crr = dfs ( i, j );
                if ( crr > ansL ) { ansL = crr; ansC = 0; }
                if ( crr == ansL ) { ansC ++; }
            }
        }
    }
    cout << ansL << " " << ansC << "\n";

    return 0;
}