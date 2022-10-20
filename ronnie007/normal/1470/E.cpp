#include<bits/stdc++.h>
using namespace std ;

#define MAXN 30007

int n , mx_cost , q ;
int a[ MAXN ] ;

long long cnt[ MAXN ][ 5 ] ;

vector < pair < int , long long > > v[ MAXN ][ 5 ] ;

long long up[ MAXN ][ 5 ] ;
long long down[ MAXN ][ 5 ] ;

void init ( ) {
    for ( int i = 0 ; i < 5 ; ++ i ) { cnt[ 0 ][ i ] = 1 ; }
    for ( int i = 1 ; i < MAXN ; ++ i ) {
        for ( int j = 0 ; j < 5 ; ++ j ) {
            for ( int t = 0 ; t <= j ; ++ t ) {
                if ( i - ( t + 1 ) >= 0 ) {
                    cnt[ i ][ j ] += cnt[ i - ( t + 1 ) ][ j - t ] ;
                }
            }
        }
    }
}


void input ( ) {
    scanf ( "%d%d%d" , &n , &mx_cost , &q ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

int get ( int pos , int lft , long long where , long long total ) {
    int l , r , mid ;
    l = pos ; r = n + 1 ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        long long sm = down[ mid ][ lft ] - down[ pos - 1 ][ lft ] ;
        long long lg = up[ mid ][ lft ] - up[ pos - 1 ][ lft ] ;
        if ( sm >= where || lg >= ( total - where + 1 ) ) { r = mid ; }
        else { l = mid ; }
    }
    while ( l <= n ) {
        long long sm = down[ l ][ lft ] - down[ pos - 1 ][ lft ] ;
        long long lg = up[ l ][ lft ] - up[ pos - 1 ][ lft ] ;
        if ( sm < where && lg < ( total - where + 1 ) ) { ++ l ; }
        else { break ; }
    }
    return l ;
}


void solve ( ) {
    for ( int i = 1 ; i <= n + 1 ; ++ i ) {
        for ( int j = 0 ; j < 5 ; ++ j ) {
            up[ i ][ j ] = down[ i ][ j ] = 0 ;
            v[ i ][ j ].clear ( ) ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j < 5 ; ++ j ) {
            for ( int t = 0 ; t <= j ; ++ t ) {
                if ( i + t <= n ) {
                    v[ i ][ j ].push_back ( { t , cnt[ n - ( i + t ) ][ j - t ] } ) ;
                }
            }
            sort ( v[ i ][ j ].begin ( ) , v[ i ][ j ].end ( ) ,
                   [ & ] ( pair < int , long long > x , pair < int , long long > y ) {
                       return a[ i + x.first ] < a[ i + y.first ] ;
                   }
                   ) ;
            int sz = v[ i ][ j ].size ( ) ;
            bool fl = false ;
            for ( int t = 0 ; t < sz ; ++ t ) {
                if ( v[ i ][ j ][ t ].first == 0 ) { fl = true ; continue ; }
                if ( fl == false ) { down[ i ][ j ] += v[ i ][ j ][ t ].second ; }
                else { up[ i ][ j ] += v[ i ][ j ][ t ].second ; }
            }
        }
    }
    for ( int i = 1 ; i <= n + 1 ; ++ i ) {
        for ( int j = 0 ; j < 5 ; ++ j ) {
            up[ i ][ j ] += up[ i - 1 ][ j ] ;
            down[ i ][ j ] += down[ i - 1 ][ j ] ;
        }
    }

    while ( q -- ) {
        long long where ;
        int id ;
        scanf ( "%d%lld" , &id , &where ) ;
        if ( where > cnt[ n ][ mx_cost ] ) {
            printf ( "-1\n" ) ;
            continue ;
        }
        long long total = cnt[ n ][ mx_cost ] ;
        int pos = 1 ;
        int lft = mx_cost ;
        while ( 1 ) {
            int nxt_skip = get ( pos , lft , where , total ) ;
            if ( nxt_skip > id ) {
                printf ( "%d\n" , a[ id ] ) ;
                break ;
            }
            total = cnt[ ( n - nxt_skip + 1 ) ][ lft ] ;
            where -= down[ nxt_skip - 1 ][ lft ] - down[ pos - 1 ][ lft ] ;
            pos = nxt_skip ;

            int sz = v[ pos ][ lft ].size ( ) ;
            bool fl = false ;
            for ( int i = 0 ; i < sz ; ++ i ) {
                if ( where > v[ pos ][ lft ][ i ].second ) {
                    where -= v[ pos ][ lft ][ i ].second ;
                    continue ;
                }
                total = v[ pos ][ lft ][ i ].second ;
                int len = v[ pos ][ lft ][ i ].first ;
                if ( pos + len >= id ) {
                    fl = true ;
                    printf ( "%d\n" , a[ pos + len - ( id - pos ) ] ) ;
                }
                else { pos += len + 1 ; lft -= len ; }
                break ;
            }
            if ( fl == true ) { break ; }
        }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    // t = 1 ;
    init ( ) ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}