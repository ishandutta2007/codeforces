#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1007

int n , q ;
int a[ MAXN ][ MAXN ] ;
int ans[ MAXN ][ MAXN ] ;

map < char , vector < vector < int > > > w ;

vector < vector < int > > mul ( vector < vector < int > > x , vector < vector < int > > y ) {
    vector < vector < int > > ret = { { 0 , 0 , 0 , 0 } , { 0 , 0 , 0 , 0 } , { 0 , 0 , 0 , 0 } , { 0 , 0 , 0 , 0 } } ;
    for ( int i = 0 ; i < 4 ; ++ i ) {
        for ( int j = 0 ; j < 4 ; ++ j ) {
            for ( int t = 0 ; t < 4 ; ++ t ) {
                ret[ i ][ j ] += x[ i ][ t ] * y[ t ][ j ] ;
                if ( ret[ i ][ j ] >= n ) { ret[ i ][ j ] %= n ; }
            }
        }
    }
    return ret ;
}

void input ( ) {
    cin >> n >> q ;
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < n ; ++ j ) {
            cin >> a[ i ][ j ] ;
        }
    }
}

void solve ( ) {
    vector < vector < int > > aux = { { 1 , 0 , 0 , 0 } , { 0 , 1 , 0 , 0 } , { 0 , 0 , 1 , 0 } , { 0 , 0 , 0 , 1 } } ;
    w[ 'U' ] = { { 1 , 0 , 0 , n - 1 } , { 0 , 1 , 0 , 0 } , { 0 , 0 , 1 , 0 } , { 0 , 0 , 0 , 1 } } ;
    w[ 'D' ] = { { 1 , 0 , 0 , 1 } , { 0 , 1 , 0 , 0 } , { 0 , 0 , 1 , 0 } , { 0 , 0 , 0 , 1 } } ;

    w[ 'L' ] = { { 1 , 0 , 0 , 0 } , { 0 , 1 , 0 , n - 1 } , { 0 , 0 , 1 , 0 } , { 0 , 0 , 0 , 1 } } ;
    w[ 'R' ] = { { 1 , 0 , 0 , 0 } , { 0 , 1 , 0 , 1 } , { 0 , 0 , 1 , 0 } , { 0 , 0 , 0 , 1 } } ;

    w[ 'I' ] = { { 1 , 0 , 0 , 0 } , { 0 , 0 , 1 , 0 } , { 0 , 1 , 0 , 0 } , { 0 , 0 , 0 , 1 } } ;
    w[ 'C' ] = { { 0 , 0 , 1 , 0 } , { 0 , 1 , 0 , 0 } , { 1 , 0 , 0 , 0 } , { 0 , 0 , 0 , 1 } } ;
    
    string s ;
    cin >> s ;
    for ( int i = 0 ; i < q ; ++ i ) {
        aux = mul ( w[ s[ i ] ] , aux ) ;
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < n ; ++ j ) {
            vector < int > hh = { i , j , a[ i ][ j ] - 1 , 1 } ;
            int c1 , c2 , val ;
            c1 = c2 = val = 0 ;
            for ( int t = 0 ; t < 4 ; ++ t ) {
                c1 += hh[ t ] * aux[ 0 ][ t ] ; c1 %= n ;
                c2 += hh[ t ] * aux[ 1 ][ t ] ; c2 %= n ;
                val += hh[ t ] * aux[ 2 ][ t ] ; val %= n ;
            }
            ans[ c1 ][ c2 ] = val + 1 ;
        }
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < n ; ++ j ) {
            cout << ans[ i ][ j ] << " " ;
        }
        cout << "\n" ;
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}