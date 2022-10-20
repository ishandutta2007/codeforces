#include<bits/stdc++.h>
using namespace std ;

#define MAXN 507

int n , m , q ;
string a[ MAXN ] ;

int mx[ 9 ][ 9 ][ MAXN ][ MAXN ] ;

int pref[ 4 ][ MAXN ][ MAXN ] ;

char c[ 4 ] = { 'R' , 'G' , 'Y' , 'B' } ;

int mxpw[ 507 ] ;

int get ( int stx , int sty , int enx , int eny , int id ) {
    return pref[ id ][ enx ][ eny ] - pref[ id ][ stx - 1 ][ eny ]
        - pref[ id ][ enx ][ sty - 1 ] + pref[ id ][ stx - 1 ][ sty - 1 ] ;
}

bool f ( int i , int j , int t ) {
    if ( t == 0 ) { return true ; }
    if ( i - t + 1 < 1 ) { return false ; }
    if ( i + t > n ) { return false ; }
    if ( j - t + 1 < 1 ) { return false ; }
    if ( j + t > m ) { return false ; }
    if ( get ( i - t + 1 , j - t + 1 , i , j , 0 ) != t * t ) { return false ; }
    if ( get ( i - t + 1 , j + 1 , i , j + t , 1 ) != t * t ) { return false ; }
    if ( get ( i + 1 , j - t + 1 , i + t , j , 2 ) != t * t ) { return false ; }
    if ( get ( i + 1 , j + 1 , i + t , j + t , 3 ) != t * t ) { return false ; }
    return true ;
}

int subrect_mx ( int stx , int sty , int enx , int eny ) {
    if ( enx < stx ) { return 0 ; }
    if ( eny < sty ) { return 0 ; }
    int exp1 = mxpw[ enx - stx + 1 ] ;
    int exp2 = mxpw[ eny - sty + 1 ] ;
    int ret = max ( mx[ exp1 ][ exp2 ][ stx ][ sty ] , mx[ exp1 ][ exp2 ][ enx - (1<<exp1) + 1 ][ sty ] ) ;
    ret = max ( ret , mx[ exp1 ][ exp2 ][ stx ][ eny - (1<<exp2) + 1 ] ) ;
    ret = max ( ret , mx[ exp1 ][ exp2 ][ enx - (1<<exp1) + 1 ][ eny - (1<<exp2) + 1 ] ) ;
    return ret ;
}

void input ( ) {
    cin >> n >> m >> q ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        a[ i ] = '#' + a[ i ] ;
    }
    
    for ( int id = 0 ; id < 4 ; ++ id ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            for ( int j = 1 ; j <= m ; ++ j ) {
                pref[ id ][ i ][ j ] = pref[ id ][ i - 1 ][ j ] + pref[ id ][ i ][ j - 1 ]
                    - pref[ id ][ i - 1 ][ j - 1 ] + ( a[ i ][ j ] == c[ id ] ) ;
            }
        }
    }
    int hh = 1 ;
    int id = 0 ;
    for ( int i = 1 ; i <= 500 ; ++ i ) {
        while ( 2 * hh < i ) {
            hh *= 2 ;
            ++ id ;
        }
        mxpw[ i ] = id ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            int l , r , mid ;
            l = 0 ;
            r = 250 ;
            while ( r - l > 3 ) {
                mid = ( l + r ) / 2 ;
                if ( f ( i , j , mid ) == true ) { l = mid ; }
                else { r = mid ; }
            }
            while ( f ( i , j , r ) == false ) { -- r ; }
            mx[ 0 ][ 0 ][ i ][ j ] = r ;
        }
    }
    for ( int exp2 = 1 ; exp2 < 9 ; ++ exp2 ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            for ( int j = 1 ; j <= m ; ++ j ) {
                mx[ 0 ][ exp2 ][ i ][ j ] = max ( mx[ 0 ][ exp2 - 1 ][ i ][ j ] , mx[ 0 ][ exp2 - 1 ][ i  ][ j + (1<<(exp2-1)) ] ) ;
            }
        }
    }
    for ( int exp1 = 1 ; exp1 < 9 ; ++ exp1 ) {
        for ( int exp2 = 0 ; exp2 < 9 ; ++ exp2 ) {
            for ( int i = 1 ; i <= n ; ++ i ) {
                for ( int j = 1 ; j <= m ; ++ j ) {
                    mx[ exp1 ][ exp2 ][ i ][ j ] = max ( mx[ exp1 - 1 ][ exp2 ][ i ][ j ] , mx[ exp1 - 1 ][ exp2 ][ i + (1<<(exp1-1)) ][ j ] ) ;
                }
            }
        }
    }
    while ( q -- ) {
        int stx , sty , enx , eny ;
        cin >> stx >> sty >> enx >> eny ;
        int l , r , mid ;
        l = 0 ; r = 250 ;
        while ( r - l > 3 ) {
            int mid = ( l + r ) / 2 ;
            if ( subrect_mx ( stx + mid - 1 , sty + mid - 1 , enx - mid , eny - mid ) >= mid ) { l = mid ; }
            else { r = mid ; }
        }
        while ( subrect_mx ( stx + r - 1 , sty + r - 1 , enx - r , eny - r ) < r ) { -- r ; }
        cout << ( 2 * r ) * ( 2 * r ) << "\n" ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}