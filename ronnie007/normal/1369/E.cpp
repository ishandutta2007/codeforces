#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 200007 ;

int n , m ;
int a[ MAXN ] , cnt[ MAXN ] ;
int diff[ MAXN ] ;
pair < int , int > b[ MAXN ] ;
vector < int > v[ MAXN ] ;
vector < int > ans ;

bool done[ MAXN ] ;

queue < int > q ;

void solve ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        cin >> b[ i ].first >> b[ i ].second ;
        ++ cnt[ b[ i ].first ] , ++ cnt[ b[ i ].second ] ;
        v[ b[ i ].first ].push_back ( i ) ;
        v[ b[ i ].second ].push_back ( i ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        diff[ i ] = a[ i ] - cnt[ i ] ;
        if ( diff[ i ] >= 0 ) {
            q.push ( i ) ;
        }
    }
    while ( q.empty ( ) == false ) {
        int x = q.front ( ) ;
        q.pop ( ) ;
        for ( auto aux : v[ x ] ) {
            if ( done[ aux ] == false ) {
                done[ aux ] = true ;
                ans.push_back ( aux ) ;
                ++ diff[ b[ aux ].first ] , ++ diff[ b[ aux ].second ] ;
                if ( diff[ b[ aux ].first ] == 0 ) {
                    q.push ( b[ aux ].first ) ;
                }
                if ( diff[ b[ aux ].second ] == 0 ) {
                    q.push ( b[ aux ].second ) ;
                }
            }
        }
    }
    if ( (int)ans.size ( ) != m ) { cout << "DEAD\n" ; }
    else {
        cout << "ALIVE\n" ;
        for ( int i = m - 1 ; i >= 0 ; -- i ) {
            cout << ans[ i ] << " " ;
        }
        cout << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}