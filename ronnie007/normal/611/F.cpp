#include<bits/stdc++.h>
using namespace std ;

#define MOD 1000000007

int n , xlen , ylen ;
string a ;
long long ans ;

vector < pair < int , int > > v ;


void sim ( int &lx , int &ly , int &hx , int &hy , int &dx , int &dy , int init , bool fl ) {
    v.clear ( ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( ly > hy || lx > hx ) { return ; }
        if ( a[ i ] == 'U' ) {
            -- dx ;
            if ( lx + dx < 1 ) {
                ans += 1LL * ( hy - ly + 1 ) * ( init + i + 1 ) ;
                ans %= MOD ;
                ++ lx ;
                if ( fl == true ) {
                    v.push_back ( { i , 1 } ) ;
                }
            }
        }
        if ( a[ i ] == 'D' ) {
            ++ dx ;
            if ( hx + dx > xlen ) {
                ans += 1LL * ( hy - ly + 1 ) * ( init + i + 1 ) ;
                ans %= MOD ;
                -- hx ;
                if ( fl == true ) {
                    v.push_back ( { i , 2 } ) ;
                }

            }
        }
        if ( a[ i ] == 'L' ) {
            -- dy ;
            if ( ly + dy < 1 ) {
                ans += 1LL * ( hx - lx + 1 ) * ( init + i + 1 ) ;
                ans %= MOD ;
                ++ ly ;
                if ( fl == true ) {
                    v.push_back ( { i , 3 } ) ;
                }

            }
        }
        if ( a[ i ] == 'R' ) {
            ++ dy ;
            if ( hy + dy > ylen ) {
                ans += 1LL * ( hx - lx + 1 ) * ( init + i + 1 ) ;
                ans %= MOD ;
                -- hy ;
                if ( fl == true ) {
                    v.push_back ( { i , 4 } ) ;
                }
            }
        }
    }
}

void input ( ) {
    cin >> n >> xlen >> ylen ;
    cin >> a ;
}

void solve ( ) {
    int lx , ly , hx , hy ;
    lx = ly = 1 ;
    hx = xlen ; hy = ylen ;
    int dx , dy ;
    dx = dy = 0 ;
    ans = 0 ;
    sim ( lx , ly , hx , hy , dx , dy , 0 , false ) ;
    sim ( lx , ly , hx , hy , dx , dy , n , true ) ;
    int sz = v.size ( ) ;
    int pos = 0 ;
    int full = 2 ;
    if ( sz == 0 ) {
        if ( lx <= hx && ly <= hy ) {
            printf ( "-1\n" ) ;
            return ;
        }
    }
    while ( lx <= hx && ly <= hy ) {
        long long aux = 0 ;
        if ( v[ pos ].second == 1 ) {
            aux = ( 1LL * ( hy - ly + 1 ) * ( ( 1LL * full * n ) % MOD + v[ pos ].first + 1 ) ) % MOD ;
            ++ lx ;
        }
        else if ( v[ pos ].second == 2 ) {
            aux = ( 1LL * ( hy - ly + 1 ) * ( ( 1LL * full * n ) % MOD + v[ pos ].first + 1 ) ) % MOD ;
            -- hx ;
        }
        else if ( v[ pos ].second == 3 ) {
            aux = ( 1LL * ( hx - lx + 1 ) * ( ( 1LL * full * n ) % MOD + v[ pos ].first + 1 ) ) % MOD ;
            ++ ly ;            
        }
        else {
            aux = ( 1LL * ( hx - lx + 1 ) * ( ( 1LL * full * n ) % MOD + v[ pos ].first + 1 ) ) % MOD ;
            -- hy ;
        }
        ans = ( ans + aux ) % MOD ;
        ++ pos ;
        if ( pos == sz ) { ++ full ; pos = 0 ; }
    }
    printf ( "%lld\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}