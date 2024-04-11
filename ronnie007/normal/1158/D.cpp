#include<bits/stdc++.h>
using namespace std ;

#define MAXN 2007

int n ;
pair < pair < int , int > , int > a[ MAXN ] ;
string s ;

int h[ MAXN ][ MAXN ] ;

int orix , oriy ;

bool used[ MAXN ] ;

long long det ( pair < long long , long long > p1 , pair < long long , long long > p2 , pair < long long , long long > p3 ) {
    long long ret = p1.first * p2.second + p1.second * p3.first + p2.first * p3.second ;
    ret -= p3.first * p2.second + p3.second * p1.first + p2.first * p1.second ;
    return ret ;
}

int get_left ( int x ) {
    int ret = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == true ) { continue ; }
        if ( ret == 0 ) { ret = i ; }
        else if ( det ( a[ x ].first , a[ ret ].first , a[ i ].first ) > 0 ) { ret = i ; }
    }
    return ret ;
}

int get_right ( int x ) {
    int ret = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == true ) { continue ; }
        if ( ret == 0 ) { ret = i ; }
        else if ( det ( a[ x ].first , a[ ret ].first , a[ i ].first ) < 0 ) { ret = i ; }
    }
    return ret ;
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ].first.first >> a[ i ].first.second ;
        a[ i ].second = i ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    cin >> s ;
}

void solve ( ) {
    cout << a[ 1 ].second << " " ;
    used[ 1 ] = true ;
    int aux = 1 ;
    for ( int i = 0 ; i < n - 2 ; ++ i ) {
        if ( s[ i ] == 'L' ) {
            aux = get_right ( aux ) ;
        }
        else {
            aux = get_left ( aux ) ;
        }
        cout << a[ aux ].second << " " ;
        used[ aux ] = true ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == false ) {
            cout << a[ i ].second << "\n" ;
        }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}