#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

const int MAXN = 200007 ;
int n , k ;
ll a[ MAXN ] ;

set < int > s ;
pair < int , int > hh[ MAXN ] ;
int coef[ MAXN ] ;
vector < int > pos[ MAXN ] ;

void input ( ) {
    cin >> n >> k ;
    for ( int i = 0 ; i <= n ; ++ i ) {
        pos[ i ].clear ( ) ;
    }
    s.clear ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    for ( int x , i = 1 ; i <= n ; ++ i ) {
        cin >> x ;
        a[ i ] -= x ;
        a[ i ] += a[ i - 1 ] ;
    }
    for ( int i = 1 ; i <= k ; ++ i ) {
        coef[ i ] = 0 ;
        cin >> hh[ i ].first >> hh[ i ].second ;
        pos[ hh[ i ].first - 1 ].push_back ( i ) ;
        pos[ hh[ i ].second ].push_back ( i ) ;
    }
}

queue < int > q ;

void mark ( int l , int r ) {
    while ( 1 ) {
        auto aux = s.lower_bound ( l ) ;
        if ( aux == s.end ( ) || *aux >= r ) { break ; }
        q.push ( *aux ) ;
        s.erase ( *aux ) ;
    }
}

void expand ( int wh ) {
    for ( auto id : pos[ wh ] ) {
        if ( ++ coef[ id ] == 2 ) {
            mark ( hh[ id ].first , hh[ id ].second ) ;
        }
    }
}

void solve ( ) {
    if ( a[ n ] != 0 ) {
        cout << "NO\n" ;
        return ;
    }
    for ( int i = 0 ; i <= n ; ++ i ) {
        if ( a[ i ] == 0 ) { q.push ( i ) ; }
        else { s.insert ( i ) ; }
    }
    while ( q.empty ( ) == false ) {
        int x = q.front ( ) ;
        q.pop ( ) ;
        expand ( x ) ;
    }
    if ( s.empty ( ) == true ) {
        cout << "YES\n" ;
        return ;
    }
    cout << "NO\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    /// t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}