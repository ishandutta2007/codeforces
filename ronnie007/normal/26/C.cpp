#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;

int N , M , n , m ;
int a , b , c ;
char ans[ 101 ][ 101 ] ;

bool solve ( ) {
    if ( N * M % 2 == 1 )
        return 0 ;
    if ( n % 2 == 1 ) {
        if ( a < m / 2 )
            return false ;
        a -= m / 2 ;
        for ( int i = 1 ; i <= m ; i += 2 )
            ans[ N ][ i ] = ans[ N ][ i + 1 ] ;
        n -- ;
    }
    if ( m % 2 == 1 ) {
        if ( b < n / 2 )
            return false ;
        b -= n / 2 ;
        for ( int i = 1 ; i <= n ; i += 2 )
            ans[ i ][ M ] = ans[ i + 1 ][ M ] ;
        m -- ;
    }
    if ( a % 2 == 1 )
        a -- ;
    if ( b % 2 == 1 )
        b -- ;
    if ( 2 * a + 2 * b + 4 * c < n * m )
        return false ;
    for ( int i = 1 ; i <= n ; i += 2 )
        for ( int j = 1 ; j <= m ; j += 2 )
            if ( a > 0 ) {
                ans[ i ][ j ] = ans[ i ][ j + 1 ] ;
                ans[ i + 1 ][ j ] = ans[ i + 1 ][ j + 1 ] ;
                a -= 2 ;

            }
            else if ( b > 0 ) {
                ans[ i ][ j ] = ans[ i + 1 ][ j ] ;
                ans[ i ][ j + 1 ] = ans[ i + 1 ][ j + 1 ] ;
                b -= 2;
            }
            else {
                ans[ i ][ j ] = ans[ i + 1 ][ j + 1 ];
                ans[ i + 1 ][ j ] = ans[ i + 1 ][ j + 1 ];
                ans[ i ][ j + 1 ] = ans[ i + 1 ][ j + 1 ];
                c -- ;
            }
    return true ;
}

int main ( ) {
    cin >> N >> M >> a >> b >> c ;
    for ( int i = 1 ; i <= N ; i ++ )
        for ( int j = 1 ; j <= M ; j ++ )
            ans[ i ][ j ] = char ( 'a' + ( i + j ) % 4 ) ;
    n = N ;
    m = M ;
    if ( !solve ( ) )
        cout << "IMPOSSIBLE" << "\n" ;
    else {
        for ( int i = 1 ; i <= N ; i++ ) {
            for ( int j = 1 ; j <= M ; j++ )
                cout << ans[ i ][ j ];
            cout << "\n" ;
        }
    }
    return 0 ;
}