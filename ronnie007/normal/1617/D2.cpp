#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 10007

int n ;
int ret[ MAXN ] ;
int a[ MAXN ] ;

int get ( int x , int y , int z ) {
    printf ( "? %d %d %d\n" , x , y , z ) ;
    fflush ( stdout ) ;
    int ans ; scanf ( "%d" , &ans ) ;
    return ans ;
}



void input ( ) {
    scanf ( "%d" ,  &n ) ;
}   

void solve ( ) {
    for ( int i = 1 ; i <= n ; i += 3 ) {
        ret[ ( i + 2 ) / 3 ] = get ( i , i + 1 , i + 2 ) ;
    }
    int pos0 , pos1 ;
    
    for ( int i = 1 ; i <= n / 3 ; ++ i ) {
        if ( ret[ i ] == 0 ) { pos0 = 3 * i - 2 ; }
        else { pos1 = 3 * i - 2 ; }
    }
    vector < int > aux ;
    for ( int i = 0 ; i < 3 ; ++ i ) {
        aux.push_back ( pos0 + i ) ;
    }
    for ( int i = 0 ; i < 3 ; ++ i ) {
        aux.push_back ( pos1 + i ) ;
    }
    int x0 , x1 ;
    
    for ( int i = 1 ; i + 2 < 6 ; ++ i ) {
        int hh = 0 ;
        if ( i == 3 ) { hh = 1 ; }
        else { hh = get ( aux[ i ] , aux[ i + 1 ] , aux[ i + 2 ] ) ; }
        
        if ( hh != 0 ) {
            x0 = aux[ i - 1 ] ;
            x1 = aux[ i + 2 ] ;
            break ;
        }
    }
    a[ x0 ] = 0 , a[ x1 ] = 1 ;
    for ( int i = 0 ; i < 6 ; ++ i ) {
        if ( aux[ i ] != x0 && aux[ i ] != x1 ) {
            a[ aux[ i ] ] = get ( x0 , x1 , aux[ i ] ) ;
        }
    }
    for ( int i = 1 ; i <= ( n / 3 ) ; ++ i ) {
        int p1 = 3 * i - 2 , p2 = 3 * i - 1 , p3 = 3 * i ;
        if ( pos0 == p1 || pos1 == p1 ) { continue ; }
        if ( ret[ i ] == 0 ) {
            int hh = get ( x1 , p1 , p2 ) ;
            if ( hh == 0 ) {
                a[ p1 ] = a[ p2 ] = 0 ;
                a[ p3 ] = get ( x0 , x1 , p3 ) ;
            }
            else {
                a[ p3 ] = 0 ;
                a[ p1 ] = get ( x0 , x1 , p1 ) ;
                a[ p2 ] = a[ p1 ] ^ 1 ;
            }
        }
        else {
            int hh = get ( x0 , p1 , p2 ) ;
            if ( hh == 1 ) {
                a[ p1 ] = a[ p2 ] = 1 ;
                a[ p3 ] = get ( x0 , x1 , p3 ) ;
            }
            else {
                a[ p3 ] = 1 ;
                a[ p1 ] = get ( x0 , x1 , p1 ) ;
                a[ p2 ] = a[ p1 ] ^ 1 ;
            }
        }
    }
    vector < int > v ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] == 0 ) {
            v.push_back ( i ) ;
        }
    }
    printf ( "! %d " , (int)v.size ( ) ) ;
    for ( auto x : v ) { printf ( "%d " , x ) ; }
    printf ( "\n" ) ;
    fflush ( stdout ) ;
}

int main ( ) {
    // ios_base :: sync_with_stdio ( false ) ;
    // cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    // t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}