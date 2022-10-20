#include<bits/stdc++.h>
using namespace std ;


#define MAXN 200007
#define MAGIC 300

int n , m ;
int x[ MAXN ] , y[ MAXN ] ;

int pref[ MAXN ] ;
int aux[ MAGIC ][ MAXN ] ;

int ans[ MAXN ] ;

vector < int > v[ MAXN ] ;

void solve_heavy ( int wh ) {
    int sz = v[ wh ].size ( ) ;
    for ( int i = 0 ; i < sz - 1 ; i += 2 ) {
        int st = v[ wh ][ i ] ;
        int en = v[ wh ][ i + 1 ] ;
        for ( int j = st ; j + x[ wh ] < en ; j += x[ wh ] + y[ wh ] ) {
            ++ pref[ j + x[ wh ] ] ;
            -- pref[ min ( j + x[ wh ] + y[ wh ] , en ) ] ;
        }
    }
}

void solve_light ( int wh ) {
    int pos = x[ wh ] + y[ wh ] ;
    int sz = v[ wh ].size ( ) ;
    for ( int i = 0 ; i < sz - 1 ; i += 2 ) {
        int st = v[ wh ][ i ] ;
        int en = v[ wh ][ i + 1 ] ;
        for ( int j = 0 ; j < y[ wh ] ; ++ j ) {
            if ( st + x[ wh ] + j >= en ) { break ; }
            ++ aux[ pos ][ st + x[ wh ] + j ] ;
            int lft = en - ( st + x[ wh ] + j ) - 1 ;
            lft /= ( x[ wh ] + y[ wh ] ) ;
            ++ lft ;
            lft *= ( x[ wh ] + y[ wh ] ) ;
            if ( lft + st + x[ wh ] + j <= m ) {
                -- aux[ pos ][ lft + st + x[ wh ] + j ] ;
            }
        }
    }
}

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> x[ i ] >> y[ i ] ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        int op , k ;
        cin >> op >> k ;
        v[ k ].push_back ( i ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        v[ i ].push_back ( m + 1 ) ;
    }
}


void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( x[ i ] + y[ i ] >= MAGIC ) {
            solve_heavy ( i ) ;
        }
        else {
            solve_light ( i ) ;
        }
    }

    int sm = 0 ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        sm += pref[ i ] ;
        ans[ i ] = sm ;
        for ( int j = 0 ; j < MAGIC ; ++ j ) {
            if ( i >= j ) {
                aux[ j ][ i ] += aux[ j ][ i - j ] ;
            }
            ans[ i ] += aux[ j ][ i ] ;
        }
        cout << ans[ i ] << "\n" ;
    }    
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}