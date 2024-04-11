#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 5e5 + 7 ;

int n , m ;
vector < pair < int , int > > v[ MAXN ] ;
int mrk[ MAXN ] , ans[ MAXN ] ;
int dist[ MAXN ] ;

queue < int > q ;

void solve ( ) {
    cin >> n >> m ;
    for ( int i = 1 , x , y , c ; i <= m ; ++ i ) {
        cin >> x >> y >> c ;
        v[ y ].push_back ( { x , c } ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        mrk[ i ] = dist[ i ] = -1 ;
    }
    dist[ n ] = 0 ;
    mrk[ n ] = 1 ;
    q.push ( n ) ;
    while ( q.empty ( ) == false ) {
        int x = q.front ( ) ;
        q.pop ( ) ;
        for ( auto [ y , c ] : v[ x ] ) {
            if ( mrk[ y ] == -1 ) {
                mrk[ y ] = c ;
            }
            else {
                if ( c != mrk[ y ] && dist[ y ] < 0 ) {
                    dist[ y ] = dist[ x ] + 1 ;
                    q.push ( y ) ;
                }
            }
        }
    }
    cout << dist[ 1 ] << "\n" ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( mrk[ i ] != -1 ) { cout << ( mrk[ i ] ^ 1 ) ; }
        else { cout << "0" ; }
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}