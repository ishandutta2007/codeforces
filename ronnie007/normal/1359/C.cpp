#include<bits/stdc++.h>
using namespace std ;

int hot , cold , sr ;

double eval ( int x ) {
    double ret = 0.0 ;
    ret += 1.0 * hot * ( x + 1 ) ;
    ret += 1.0 * cold * x ;
    ret /= ( 2 * x + 1 ) ;
    return ret ;
}

void input ( ) {
    scanf ( "%d%d%d" , &hot , &cold , &sr ) ;
}

void solve ( ) {
    if ( sr >= hot ) { printf ( "1\n" ) ; return ; }
    if ( sr <= ( hot + cold ) / 2 ) { printf ( "2\n" ) ; return ; }
    int l , r , mid ;
    l = 0 ;
    r = 1 ;
    for ( int i = 1 ; i <= 8 ; ++ i ) { r *= 10 ; }
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        double ret = eval ( mid ) ;
        if ( ret > sr ) { l = mid ; }
        else { r = mid ; }
    }
    double mn = fabs ( ( hot + cold ) / 2.0 - sr ) ;
    int id = 2 ;
    for ( int i = l ; i <= r + 1 ; ++ i ) {
        if ( mn > fabs ( sr - eval ( i ) ) ) {
            mn = fabs ( sr - eval ( i ) ) ;
            id = 2 * i + 1 ;
        }
    }
    printf ( "%d\n" , id ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}