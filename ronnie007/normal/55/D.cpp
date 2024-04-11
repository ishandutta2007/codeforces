#include<bits/stdc++.h>
using namespace std ;


string st , en ;

long long dp[ 2 ][ 130 ][ 2522 ][ 2 ] ;

string conv ( long long arg ) {
    if ( arg == 0 ) { return "0" ; }
    string aux ;
    aux.clear ( ) ;
    while ( arg > 0 ) {
        aux += char ( ( arg % 10 ) + '0' ) ;
        arg /= 10 ;
    }
    string ret ;
    ret.clear ( ) ;
    for ( int i = aux.size ( ) - 1 ; i >= 0 ; -- i ) {
        ret += aux[ i ] ;
    }
    return ret ;
}


long long f ( string bound ) {
    int sz = bound.size ( ) ;
    int old , nxt ;
    old = 0 ; nxt = 1 ;
    for ( int i = 0 ; i < 2 ; ++ i ) {
        for ( int j = 0 ; j <= 129 ; ++ j ) {
            for ( int t = 0 ; t <= 2520 ; ++ t ) {
                for ( int z = 0 ; z < 2 ; ++ z ) {
                    dp[ i ][ j ][ t ][ z ] = 0 ;
                }
            }
        }
    }
    dp[ old ][ 0 ][ 0 ][ 1 ] = 1 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        for ( int j = 0 ; j < 128 ; ++ j ) {
            for ( int t = 0 ; t < 2520 ; ++ t ) {
                for ( int z = 0 ; z < 2 ; ++ z ) {
                    if ( dp[ old ][ j ][ t ][ z ] == 0 ) { continue ; }
                    for ( int dig = 0 ; dig < 10 ; ++ dig ) {
                        if ( z == 1 && dig > ( bound[ i ] - '0' ) ) { break ; }
                        int nw = z ;
                        if ( dig < bound[ i ] - '0' ) { nw = 0 ; }
                        int nwmask = j ;
                        if ( dig > 1 ) {
                            if ( dig < 6 ) {
                                nwmask |= (1<<(dig-2)) ;
                                if ( dig == 4 ) { nwmask |= 1 ; }
                            }
                            else if ( dig == 6 ) {
                                nwmask |= (1<<0) ;
                                nwmask |= (1<<1) ;
                            }
                            else {
                                nwmask |= (1<<(dig-3)) ;
                                if ( dig == 9 ) { nwmask |= 2 ; }
                                if ( dig == 8 ) { nwmask |= 1 ; nwmask |= 4 ; }
                            }
                        }
                        dp[ nxt ][ nwmask ][ ( 10 * t + dig ) % 2520 ][ nw ] += dp[ old ][ j ][ t ][ z ] ;
                    }
                    dp[ old ][ j ][ t ][ z ] = 0 ;
                }
            }
        }
        old ^= 1 ; nxt ^= 1 ;
    }
    long long ans = 0 ;
    for ( int j = 0 ; j < 128 ; ++ j ) {
        for ( int t = 0 ; t < 2520 ; ++ t ) {
            bool fl = true ;
            for ( int z = 2 ; z < 10 ; ++ z ) {
                int sr ;
                if ( z == 6 ) {
                    sr = 3 ;
                }
                else if ( z < 6 ) { sr = (1<<(z-2)) ; }
                else { sr = (1<<(z-3)) ; }
                if ( ( j & sr ) == sr ) {
                    if ( ( t % z ) != 0 ) {
                        fl = false ;
                        break ;
                    }
                }
            }
            if ( fl == false ) { continue ; }
            for ( int z = 0 ; z < 2 ; ++ z ) {
                ans += dp[ old ][ j ][ t ][ z ] ;
            }
        }
    }
    return ans ;
}

void input ( ) {
    long long l , r ;
    cin >> l >> r ;
    -- l ;
    st = conv ( l ) ;
    en = conv ( r ) ;
}

void solve ( ) {
    cout << f ( en ) - f ( st ) << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}