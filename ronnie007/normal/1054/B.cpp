#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int mx = -1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] > mx ) {
            if ( a[ i ] != mx + 1 ) {
                printf ( "%d\n" , i ) ;
                return ;
            }
            mx = a[ i ] ;
        }
    }
    printf ( "-1\n" ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}