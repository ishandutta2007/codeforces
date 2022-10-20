#include<bits/stdc++.h>
using namespace std ;

int aux[ 6 ] = { 2 , 3 , 5 , 7 , 11 , 13 } ;

int sz ;
vector < int > v ;

void init ( ) {
    for ( int i = 0 ; i < 6 ; ++ i ) {
        for ( int j = i + 1 ; j < 6 ; ++ j ) {
            v.push_back ( aux[ i ] * aux[ j ] ) ;
        }
    }
    sz = v.size ( ) ;
}

int n ;

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    int i , j , t ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        for ( int j = i + 1 ; j < sz ; ++ j ) {
            for ( int t = j + 1 ; t < sz ; ++ t ) {
                if ( v[ i ] + v[ j ] + v[ t ] >= n ) { continue ; }
                int x = n - v[ i ] - v[ j ] - v[ t ] ;
                if ( x != v[ i ] && x != v[ j ] && x != v[ t ] ) {
                    cout << "YES\n" ;
                    cout << v[ i ] << " " << v[ j ] << " " << v[ t ] << " " << x << "\n" ;
                    return ;
                }
            }
        }
    }
    cout << "NO\n" ; 
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    init ( ) ;
    int t ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}