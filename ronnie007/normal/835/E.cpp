#include<bits/stdc++.h>
using namespace std ;

int n , x , y ;

int a , b ;

int diff ;

void ask ( int mask ) {
    int sz = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( ( i & mask ) > 0 ) { ++ sz ; }
    }
    if ( sz == 0 ) { return ; }
    printf ( "? %d" , sz ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( ( i & mask ) > 0 ) {
            printf ( " %d" , i + 1 ) ;
        }
    }
    printf ( "\n" ) ;
    fflush ( stdout ) ;
    int ans = 0 ;
    scanf ( "%d" , &ans ) ;
    if ( ans != 0 && ans != x ) {
        diff += mask ;
    }
}

vector < int > v ;

bool f ( int sr ) {
    printf ( "? %d" , sr + 1 ) ;
    for ( int i = 0 ; i <= sr ; ++ i ) {
        printf ( " %d" , v[ i ] + 1 ) ;
    }
    printf ( "\n" ) ;
    fflush ( stdout ) ;
    int ans ;
    scanf ( "%d" , &ans ) ;
    if ( ans != 0 && ans != x ) { return true ; }
    return false ;
}

void input ( ) {
    scanf ( "%d%d%d" , &n , &x , &y ) ;
}

void solve ( ) {
    for ( int i = 0 ; i < 10 ; ++ i ) {
        ask ( (1<<i) ) ;
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( ( i ^ diff ) < i ) {
            v.push_back ( i ) ;
        }
    }
    int l , r , mid ;
    l = 0 ;
    r = v.size ( ) - 1 ;
    while ( l != r ) {
        int mid = ( l + r ) / 2 ;
        if ( f ( mid ) == true ) { r = mid ; }
        else { l = mid + 1 ; }
    }
    printf ( "! %d %d\n" , ( v[ l ] ^ diff ) + 1 , v[ l ] + 1 ) ;
    fflush ( stdout ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}