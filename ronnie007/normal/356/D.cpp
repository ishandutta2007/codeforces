#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 70007

int n , s ;
pair < int , int > a[ MAXN ] ;
int rv[ MAXN ] ;
int lst[ MAXN ] ;
bitset < MAXN > w ;

bool used[ MAXN ] ;
int nxt[ MAXN ] ;

void input ( ) {
    cin >> n >> s ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ].first ;
        a[ i ].second = i ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        rv[ a[ i ].second ] = i ;
    }
}

void solve ( ) {
    w[ a[ n ].first ] = 1 ;
    bitset < MAXN > aux = w ;
    for ( int i = 1 ; i < n ; ++ i ) {
        w = w | ( w << a[ i ].first ) ;
        aux = aux ^ w ;

        for ( int pos = aux._Find_first ( ) ; pos < MAXN ; pos = aux._Find_next ( pos ) ) {
            lst[ pos ] = i ;
        }

        aux = w ;
    }
    if ( w[ s ] == false ) {
        cout << "-1\n" ;
        return ;
    }
    int hh = s ;
    while ( hh > a[ n ].first ) {
        int id = lst[ hh ] ;
        hh -= a[ id ].first ;
        used[ id ] = true ;
    }
    int pos = -1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == true ) { continue ; }
        nxt[ i ] = pos ;
        pos = i ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ rv[ i ] ] == true ) {
            cout << a[ rv[ i ] ].first << " 0\n" ;
        }
        else {
            if ( nxt[ rv[ i ] ] == -1 ) {
                cout << a[ rv[ i ] ].first << " 0\n" ;
            }
            else {
                cout << a[ rv[ i ] ].first - a[ nxt[ rv[ i ] ] ].first << " 1 " << a[ nxt[ rv[ i ] ] ].second << "\n" ;
            }
        }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}