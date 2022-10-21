#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;
int nxt[ MAXN ] ;
int prv[ MAXN ] ;

bool f[ MAXN ] ;

struct tuhla {
    int l , r ;
    int cnt ;
    tuhla ( ) { l = r = cnt = 0 ; }
    tuhla ( int _l , int _r , int _cnt ) {
        l = _l ;
        r = _r ;
        cnt = _cnt ;
    }
    bool operator < ( tuhla other ) const {
        if ( cnt != other.cnt ) { return ( cnt < other.cnt ) ; }
        return ( l > other.l ) ;
    }
};

priority_queue < struct tuhla > q ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        if ( i > 1 ) { prv[ i ] = i - 1 ; }
        if ( i < n ) { nxt[ i ] = i + 1 ; }
    }
}

void solve ( ) {
    int cnt = 1 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        if ( a[ i ] == a[ i - 1 ] ) {
            ++ cnt ;
        }
        else {
            q.push ( tuhla ( i - cnt , i - 1 , cnt ) ) ;
            cnt = 1 ;
        }
    }
    q.push ( tuhla ( n - cnt + 1 , n , cnt ) ) ;
    int ans = 0 ;
    while ( q.empty ( ) == false ) {
        tuhla aux = q.top ( ) ;
        q.pop ( ) ;
        if ( f[ aux.l ] == true ) { continue ; }
        ++ ans ;
        int pos = aux.l ;
        while ( 1 ) {
            f[ pos ] = true ;
            if ( pos == aux.r ) { break ; }
            pos = nxt[ pos ] ;
        }
        int h1 = prv[ aux.l ] ;
        int h2 = nxt[ aux.r ] ;
        nxt[ h1 ] = h2 ;
        prv[ h2 ] = h1 ;
        if ( h1 == 0 || h2 == 0 ) { continue ; }
        if ( a[ h1 ] != a[ h2 ] ) { continue ; }
        int sr = a[ h1 ] ;
        int cnt = 0 ;
        while ( h1 > 0 ) {
            ++ cnt ;
            if ( prv[ h1 ] == 0 || a[ prv[ h1 ] ] != sr ) { break ; }
            h1 = prv[ h1 ] ;
        }
        while ( h2 > 0 ) {
            ++ cnt ;
            if ( nxt[ h2 ] == 0 || a[ nxt[ h2 ] ] != sr ) { break ; }
            h2 = nxt[ h2 ] ;
        }
        q.push ( tuhla ( h1 , h2 , cnt ) ) ;
    }
    printf ( "%d\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}