#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , k ;
int a[ MAXN ] ;
long long dp[ 2 ][ MAXN ] ;

int f[ MAXN ] ;
long long cnt ;
int st , en ;

void add ( int x ) {
    cnt += f[ x ] ++ ;
}
void rem ( int x ) {
    cnt -= -- f[ x ] ;
}

void fix_interval ( int l , int r ) {
    while ( st < l ) { rem ( a[ st ++ ] ) ; }
    while ( st > l ) { add ( a[ -- st ] ) ; }
    while ( en < r ) { add ( a[ ++ en ] ) ; }
    while ( en > r ) { rem ( a[ en -- ] ) ; }
}

void rec ( int l , int r , int l_bound , int r_bound , int prv ) {
    if ( l > r ) { return ; }
    int mid = ( l + r ) / 2 ;
    int id = -1 ;
    long long ans = -1 ;
    for ( int i = min ( mid , r_bound ) ; i >= l_bound ; -- i ) {
        fix_interval ( i , mid ) ;
        long long aux = dp[ prv ][ i - 1 ] + cnt ;
        if ( ans < 0 ) {
            ans = aux ;
            id = i ;
        }
        if ( ans > aux ) {
            ans = aux ;
            id = i ;
        }
    }
    dp[ prv ^ 1 ][ mid ] = ans ;
    rec ( l , mid - 1 , l_bound , id , prv ) ;
    rec ( mid + 1 , r , id , r_bound , prv ) ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        add ( a[ i ] ) ;
        dp[ 0 ][ i ] = cnt ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        f[ i ] = 0 ;
    }
    st = en = 1 ;
    f[ a[ 1 ] ] = 1 ;
    cnt = 0 ;
    int prv , nxt ;
    prv = 0 ; nxt = 1 ;
    for ( int i = 2 ; i <= k ; ++ i ) {
        rec ( 1 , n , 1 , n , prv ) ;
        prv ^= 1 ; nxt ^= 1 ;
    }
    printf ( "%I64d\n" , dp[ prv ][ n ] ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}