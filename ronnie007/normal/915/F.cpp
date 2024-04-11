#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007

int n ;
int a[ MAXN ] ;
vector < int > v[ MAXN ] ;

pair < int , int > b[ MAXN ] ;
int prv[ MAXN ] ;
int rnk[ MAXN ] ;
int comp[ MAXN ] ;

long long ans ;

int find ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = find ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

void UNITE ( int x , int y , int coef ) {
    int k1 = find ( x ) ;
    int k2 = find ( y ) ;
    if ( k1 != k2 ) {
        ans += 1LL * comp[ k1 ] * comp[ k2 ] * coef ;
        if ( rnk[ k1 ] > rnk[ k2 ] ) {
            prv[ k2 ] = k1 ;
            comp[ k1 ] += comp[ k2 ] ;
        }
        else if ( rnk[ k1 ] < rnk[ k2 ] ) {
            prv[ k1 ] = k2 ;
            comp[ k2 ] += comp[ k1 ] ;
        }
        else {
            ++ rnk[ k1 ] ;
            prv[ k2 ] = k1 ;
            comp[ k1 ] += comp[ k2 ] ;
        }
    }
}

void add ( int vertex , int coef ) {
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ] ;
        if ( coef > 0 && a[ h ] <= a[ vertex ] ) {
            UNITE ( vertex , h , coef ) ;
        }
        if ( coef < 0 && a[ h ] >= a[ vertex ] ) {
            UNITE ( vertex , h , coef ) ;
        }
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        b[ i ] = { a[ i ] , i } ;
    }
    int x , y ;
    for ( int i = 1 ; i < n ; ++ i ) {
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
    sort ( b + 1 , b + n + 1 ) ;
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        prv[ i ] = -1 ;
        rnk[ i ] = 0 ;
        comp[ i ] = 1 ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        add ( b[ i ].second , b[ i ].first ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        prv[ i ] = -1 ;
        rnk[ i ] = 0 ;
        comp[ i ] = 1 ;
    }
    
    for ( int i = n ; i >= 1 ; -- i ) {
        add ( b[ i ].second , - b[ i ].first ) ;
    }
    printf ( "%I64d\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}