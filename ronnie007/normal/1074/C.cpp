#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007

int n ;
pair < int , int > a[ MAXN ] ;

int coef[ 6 ] ;
int dp[ MAXN ][ 4 ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
    }
}

void solve ( ) {
    int ans = 0 ;
    for ( int mask = 0 ; mask < 64 ; ++ mask ) {
        coef[ 0 ] = ( (mask&1) > 0 ) + ( (mask&16) == 0 ) - ( (mask&1) == 0 ) - ( (mask&16) > 0 ) ;
        coef[ 1 ] = ( (mask&2) > 0 ) + ( (mask&32) == 0 ) - ( (mask&2) == 0 ) - ( (mask&32) > 0 ) ;
        coef[ 2 ] = ( (mask&1) == 0 ) + ( (mask&4) > 0 ) - ( (mask&1) > 0 ) - ( (mask&4) == 0 ) ;
        coef[ 3 ] = ( (mask&2) == 0 ) + ( (mask&8) > 0 ) - ( (mask&2) > 0 ) - ( (mask&8) == 0 ) ;
        coef[ 4 ] = ( (mask&4) == 0 ) + ( (mask&16) > 0 ) - ( (mask&4) > 0 ) - ( (mask&16) == 0 ) ;
        coef[ 5 ] = ( (mask&8) == 0 ) + ( (mask&32) > 0 ) - ( (mask&8) > 0 ) - ( (mask&32) == 0 ) ;
        int base = 0 ;
        for ( int j = 1 ; j <= 3 ; ++ j ) {
            int pref = dp[ j - 1 ][ j - 1 ] ;
            for ( int i = j ; i <= n ; ++ i ) {
                dp[ i ][ j ] = coef[ base ] * a[ i ].first + coef[ base + 1 ] * a[ i ].second + pref ;
                pref = max ( pref , dp[ i ][ j - 1 ] ) ;
                if ( j == 3 ) {
                    ans = max ( ans , dp[ i ][ j ] ) ;
                }
            }
            base += 2 ;
        }
    }
    printf ( "%d " , ans ) ;
    int hh = 0 ;
    sort ( a + 1 , a + n + 1 ) ;
    hh += a[ n ].first - a[ 1 ].first ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        swap ( a[ i ].first , a[ i ].second ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    hh += a[ n ].first - a[ 1 ].first ;
    hh *= 2 ;
    for ( int i = 4 ; i <= n ; ++ i ) {
        printf ( "%d " , hh ) ;
    }
    printf ( "\n" ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}