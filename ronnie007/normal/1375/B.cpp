#include<bits/stdc++.h>
using namespace std ;

#define MAXN 507

int n , m ;
int a[ MAXN ][ MAXN ] ;

int dx[ 4 ] = { 1 , -1 , 0 , 0 } ;
int dy[ 4 ] = { 0 , 0 , 1 , -1 } ;

bool check ( int x , int y ) {
    if ( x < 1 || x > n ) { return false ; }
    if ( y < 1 || y > m ) { return false ; }
    return true ;
}

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            cin >> a[ i ][ j ] ;
        }
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            int cnt = 0 ;
            for ( int t = 0 ; t < 4 ; ++ t ) {
                int nx = i + dx[ t ] ;
                int ny = j + dy[ t ] ;
                if ( check ( nx , ny ) == true ) { ++ cnt ; }
            }
            if ( a[ i ][ j ] > cnt ) {
                cout << "NO\n" ;
                return ;
            }
            a[ i ][ j ] = cnt ;
        }
    }
    cout << "YES\n" ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            cout << a[ i ][ j ] << " " ;
        }
        cout << "\n" ;
    }
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