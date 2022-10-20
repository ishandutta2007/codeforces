#include<bits/stdc++.h>
using namespace std ;

#define MAXN 5007

int n , st , en ;
int x[ MAXN ] ;

int a[ MAXN ] ;
int b[ MAXN ] ;
int c[ MAXN ] ;
int d[ MAXN ] ;

long long dp[ 2 ][ MAXN ] ;

bool st_fl , en_fl ;

void upd_chain_start ( int i , int prv , int nxt ) {
    for ( int j = 1 ; j <= n ; ++ j ) {
        if ( dp[ prv ][ j ] == -1 ) { continue ; }
        if ( st_fl == true && j == 1 ) { continue ; }
        long long aux = dp[ prv ][ j ] + d[ i ] + a[ i ] ;
        if ( dp[ nxt ][ j ] < 0 || dp[ nxt ][ j ] > aux ) {
            dp[ nxt ][ j ] = aux ;
        }
    }
}

void upd_chain_end ( int i , int prv , int nxt ) {
    for ( int j = 1 ; j <= n ; ++ j ) {
        if ( dp[ prv ][ j ] == -1 ) { continue ; }
        if ( en_fl == true && j == 1 ) { continue ; }
        long long aux = dp[ prv ][ j ] + b[ i ] + c[ i ] ;
        if ( dp[ nxt ][ j ] < 0 || dp[ nxt ][ j ] > aux ) {
            dp[ nxt ][ j ] = aux ;
        }
    }
}

void upd_new_chain ( int i , int prv , int nxt ) {
    for ( int j = 1 ; j <= n ; ++ j ) {
        if ( dp[ prv ][ j - 1 ] == -1 ) { continue ; }
        if ( st_fl == true && en_fl == true && j == 2 ) { continue ; }
        long long aux = dp[ prv ][ j - 1 ] + 2 * x[ i ] + a[ i ] + c[ i ] ;
        if ( dp[ nxt ][ j ] < 0 || dp[ nxt ][ j ] > aux ) {
            dp[ nxt ][ j ] = aux ;
        }
    }
}

void combine_chains ( int i , int prv , int nxt ) {
    for ( int j = 1 ; j < n ; ++ j ) {
        if ( dp[ prv ][ j + 1 ] == -1 ) { continue ; }
        long long aux = dp[ prv ][ j + 1 ] - 2 * x[ i ] + b[ i ] + d[ i ] ;
        if ( dp[ nxt ][ j ] < 0 || dp[ nxt ][ j ] > aux ) {
            dp[ nxt ][ j ] = aux ;
        }
    }
}

void mark_st ( int i , int prv , int nxt ) {
    for ( int j = 1 ; j <= n ; ++ j ) {
        if ( dp[ prv ][ j ] == -1 ) { continue ; }
        long long aux = dp[ prv ][ j ] + d[ i ] - x[ i ] ;
        if ( dp[ nxt ][ j ] < 0 || dp[ nxt ][ j ] > aux ) {
            dp[ nxt ][ j ] = aux ;
        }
    }
    for ( int j = 1 ; j <= n ; ++ j ) {
        if ( dp[ prv ][ j - 1 ] == -1 ) { continue ; }
        long long aux = dp[ prv ][ j - 1 ] + c[ i ] + x[ i ] ;
        if ( dp[ nxt ][ j ] < 0 || dp[ nxt ][ j ] > aux ) {
            dp[ nxt ][ j ] = aux ;
        }
    }
    if ( en_fl == true && i != 1 ) { dp[ nxt ][ 1 ] = -1 ; }
}

void mark_en ( int i , int prv , int nxt ) {
    for ( int j = 1 ; j <= n ; ++ j ) {
        if ( dp[ prv ][ j ] == -1 ) { continue ; }
        long long aux = dp[ prv ][ j ] + b[ i ] - x[ i ] ;
        if ( dp[ nxt ][ j ] < 0 || dp[ nxt ][ j ] > aux ) {
            dp[ nxt ][ j ] = aux ;
        }
    }
    for ( int j = 1 ; j <= n ; ++ j ) {
        if ( dp[ prv ][ j - 1 ] == -1 ) { continue ; }
        long long aux = dp[ prv ][ j - 1 ] + a[ i ] + x[ i ] ;
        if ( dp[ nxt ][ j ] < 0 || dp[ nxt ][ j ] > aux ) {
            dp[ nxt ][ j ] = aux ;
        }
    }
    if ( st_fl == true && i != 1 ) { dp[ nxt ][ 1 ] = -1 ; }
}

void input ( ) {
    cin >> n >> st >> en ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> x[ i ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> b[ i ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> c[ i ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> d[ i ] ;
    }
}

void solve ( ) {
    int prv , nxt ;
    prv = 0 ; nxt = 1 ;
    for ( int i = 0 ; i <= n ; ++ i ) {
        dp[ prv ][ i ] = -1 ;
        dp[ nxt ][ i ] = -1 ;
    }
    dp[ prv ][ 0 ] = 0 ;
    for ( int i = n ; i >= 1 ; -- i ) {
        if ( i != st && i != en ) {
            upd_chain_start ( i , prv , nxt ) ;
            upd_chain_end ( i , prv , nxt ) ;
            upd_new_chain ( i , prv , nxt ) ;
            combine_chains ( i , prv , nxt ) ;
        }
        else if ( i == st ) {
            mark_st ( i , prv , nxt ) ;
            st_fl = true ;
        }
        else {
            mark_en ( i , prv , nxt ) ;
            en_fl = true ;
        }
        for ( int j = 0 ; j <= n ; ++ j ) {
            dp[ prv ][ j ] = -1 ;
        }
        prv ^= 1 ; nxt ^= 1 ; 
    }
    cout << dp[ prv ][ 1 ] << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}