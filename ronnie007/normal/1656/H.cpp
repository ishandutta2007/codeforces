#include<bits/stdc++.h>
using namespace std ;
typedef __int128 ll ;


#define MAXN 1025

ll gcd ( ll x , ll y ) {
    if ( x < y ) { swap ( x , y ) ; }
    if ( y == 0 ) { return x ; }
    return gcd ( y , ( x % y ) ) ;
}

class Tree {
public :
    ll ori ;
    ll tr[ 2 * MAXN ] ;
    void init ( int where , int IL , int IR , ll *ptr ) {
        if ( IL == IR ) {
            ll aux = gcd ( ori , ptr[ IL ] ) ;
            tr[ where ] = ori / aux ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid , ptr ) ;
        init ( 2 * where + 1 , mid + 1 , IR , ptr ) ;
        tr[ where ] = gcd ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    void update ( int where , int IL , int IR , int pos , ll nw ) {
        if ( IL == IR ) {
            ll aux = gcd ( ori , nw ) ;
            tr[ where ] = ori / aux ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , nw ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , nw ) ;
        }
        tr[ where ] = gcd ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    ll query ( ) { return tr[ 1 ] ; }
};

Tree tr_a[ MAXN ] , tr_b[ MAXN ] ;

int n , m ;
ll a[ MAXN ] , b[ MAXN ] ;

ll read ( ) {
    string s ; cin >> s ;
    ll ret = 0 ;
    for ( auto c : s ) {
        ret = ( ret * 10 + ( c - '0' ) ) ;
    }
    return ret ;
}
void output ( ll hh ) {
    string s ;
    while ( hh > 0 ) {
        s += char ( ( hh % 10 ) + '0' ) ;
        hh /= 10 ;
    }
    reverse ( s.begin ( ) , s.end ( ) ) ;
    cout << s << " " ;
}

bool kill_a[ MAXN ] , kill_b[ MAXN ] ;

bool done ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( kill_a[ i ] == false && tr_a[ i ].query ( ) != 1 ) {
            return false ;
        }
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        if ( kill_b[ i ] == false && tr_b[ i ].query ( ) != 1 ) {
            return false ;
        }
    }
    return true ;
}

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        a[ i ] = read ( ) ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        b[ i ] = read ( ) ;
    }
}

void solve ( ) {
    int cnt_a = n , cnt_b = m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        kill_a[ i ] = false ;
        tr_a[ i ].ori = a[ i ] ;
        tr_a[ i ].init ( 1 , 1 , m , b ) ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        kill_b[ i ] = false ;
        tr_b[ i ].ori = b[ i ] ;
        tr_b[ i ].init ( 1 , 1 , n , a ) ;
    }
    while ( cnt_a > 0 && cnt_b > 0 && done ( ) == false ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            if ( kill_a[ i ] == false && tr_a[ i ].query ( ) > 1 ) {
                kill_a[ i ] = true , -- cnt_a ; 
                for ( int j = 1 ; j <= m ; ++ j ) {
                    tr_b[ j ].update ( 1 , 1 , n , i , 1 ) ;
                }
            }
        }
        for ( int i = 1 ; i <= m ; ++ i ) {
            if ( kill_b[ i ] == false && tr_b[ i ].query ( ) > 1 ) {
                kill_b[ i ] = true , -- cnt_b ;
                for ( int j = 1 ; j <= n ; ++ j ) {
                    tr_a[ j ].update ( 1 , 1 , m , i , 1 ) ;
                }
            }
        }
    }
    if ( cnt_a == 0 || cnt_b == 0 ) {
        cout << "NO\n" ;
        return ;
    }
    cout << "YES\n" ;
    cout << cnt_a << " " << cnt_b << "\n" ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( kill_a[ i ] == false ) { output ( a[ i ] ) ; }
    }
    cout << "\n" ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        if ( kill_b[ i ] == false ) { output ( b[ i ] ) ; }
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}