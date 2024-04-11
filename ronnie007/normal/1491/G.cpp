#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;
bool used[ MAXN ] ;

vector < vector < int > > cycles ;

vector < pair < int , int > > ans ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == true ) { continue ; }
        vector < int > aux ;
        int x = i ;
        while ( used[ x ] == false ) {
            used[ x ] = true ;
            aux.push_back ( x ) ;
            x = a[ x ] ;
        }
        if ( aux.size ( ) > 1 ) {
            cycles.push_back ( aux ) ;
        }
    }
    int sz = cycles.size ( ) ;
    for ( int i = 0 ; i + 1 < sz ; i += 2 ) {
        ans.push_back ( { cycles[ i ][ 0 ] , cycles[ i + 1 ][ 0 ] } ) ;
        int len1 = cycles[ i ].size ( ) ;
        int len2 = cycles[ i + 1 ].size ( ) ;
        for ( int j = 1 ; j < len1 ; ++ j ) {
            ans.push_back ( { cycles[ i + 1 ][ 0 ] , cycles[ i ][ j ] } ) ;
        }
        for ( int j = 1 ; j < len2 ; ++ j ) {
            ans.push_back ( { cycles[ i ][ 0 ] , cycles[ i + 1 ][ j ] } ) ;
        }
        ans.push_back ( { cycles[ i ][ 0 ] , cycles[ i + 1 ][ 0 ] } ) ;
    }
    if ( ( sz % 2 ) == 1 ) {
        if ( cycles[ sz - 1 ].size ( ) != n ) {
            int ori ;
            if ( sz > 1 ) { ori = cycles[ 0 ][ 0 ] ; }
            else {
                for ( int i = 1 ; i <= n ; ++ i ) {
                    if ( a[ i ] == i ) { ori = i ; }
                }
            }
            ans.push_back ( { ori , cycles[ sz - 1 ][ 0 ] } ) ;
            int len = cycles[ sz - 1 ].size ( ) ;
            for ( int i = 1 ; i < len ; ++ i ) {
                ans.push_back ( { ori , cycles[ sz - 1 ][ i ] } ) ;
            }
            ans.push_back ( { ori , cycles[ sz - 1 ][ 0 ] } ) ;
        }
        else {
            ans.push_back ( { cycles[ sz - 1 ][ 0 ] , cycles[ sz - 1 ][ 1 ] } ) ;
            ans.push_back ( { cycles[ sz - 1 ][ 1 ] , cycles[ sz - 1 ][ 2 ] } ) ;
            for ( int i = 3 ; i < n ; ++ i ) {
                ans.push_back ( { cycles[ sz - 1 ][ 1 ] , cycles[ sz - 1 ][ i ] } ) ;
            }
            ans.push_back ( { cycles[ sz - 1 ][ 0 ] , cycles[ sz - 1 ][ 2 ] } ) ;
            ans.push_back ( { cycles[ sz - 1 ][ 0 ] , cycles[ sz - 1 ][ 1 ] } ) ;
        }
    }
    cout << ans.size ( ) << "\n" ;
    for ( auto [ x , y ] : ans ) {
        cout << x << " " << y << "\n" ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}