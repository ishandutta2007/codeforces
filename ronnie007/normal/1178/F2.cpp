#include<bits/stdc++.h>
using namespace std ;

#define MOD 998244353
#define MAXN 1007


int n , k ;
int init[ 1000007 ] ;

struct tuhla {
    int col , len ;
};
tuhla a[ MAXN ] ;
int dp[ MAXN ][ MAXN ] ;

vector < int > prec[ MAXN ] ;
int mnval[ MAXN ][ MAXN ] ;
int st[ MAXN ] ;
int en[ MAXN ] ;

bool check ( ) {
    set < int > s ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        prec[ init[ i ] ].push_back ( i ) ;
    }
    for ( int i = 1 ; i <= k ; ++ i ) {
        auto it = s.upper_bound ( prec[ i ].front ( ) ) ;
        if ( it != s.end ( ) && (*it) < prec[ i ].back ( ) ) { return false ; }
        for ( auto x : prec[ i ] ) {
            s.insert ( x ) ;
        }
    }
    return true ;
}

void input ( ) {
    scanf ( "%d%d" , &k , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &init[ i ] ) ;
    }
}

void solve ( ) {
    if ( check ( ) == false ) {
        printf ( "0\n" ) ;
        return ;
    }
    int cnt = 1 ;
    int dummy = n ;
    n = 0 ;
    for ( int i = 2 ; i <= dummy ; ++ i ) {
        if ( init[ i ] == init[ i - 1 ] ) { ++ cnt ; }
        else {
            a[ ++ n ] = (tuhla){ init[ i - 1 ] , cnt } ;
            cnt = 1 ;
        }
    }
    a[ ++ n ] = (tuhla){ init[ dummy ] , cnt } ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        mnval[ i ][ i ] = a[ i ].col ;
        for ( int j = i + 1 ; j <= n ; ++ j ) {
            mnval[ i ][ j ] = min ( mnval[ i ][ j - 1 ] , a[ j ].col ) ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        en[ a[ i ].col ] = i ;
    }
    for ( int i = n ; i >= 1 ; -- i ) {
        st[ a[ i ].col ] = i ;
    }
    for ( int i = 1 ; i <= k ; ++ i ) { prec[ i ].clear ( ) ; }
    for ( int i = 1 ; i <= n ; ++ i ) {
        prec[ a[ i ].col ].push_back ( i ) ;
    }
    for ( int i = 0 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j < i ; ++ j ) {
            dp[ i ][ j ] = 1 ;
        }
    }
    for ( int diff = 0 ; diff < n ; ++ diff ) {
        for ( int l = 1 ; l + diff <= n ; ++ l ) {
            int r = l + diff ;
            int sr = mnval[ l ][ r ] ;
            if ( st[ sr ] < l || r < en[ sr ] ) { continue ; }

            int coef = 1 ;
            int sz = prec[ sr ].size ( ) ;
            for ( int i = 0 ; i < sz - 1 ; ++ i ) {
                coef = ( 1LL * coef * dp[ prec[ sr ][ i ] + 1 ][ prec[ sr ][ i + 1 ] - 1 ] ) % MOD ;
            }
            
            int aux1 , aux2 ;
            aux1 = aux2 = 0 ;
            for ( int t = l ; t <= st[ sr ] ; ++ t ) {
                int add = 1 ;
                if ( l < t ) { add = dp[ l ][ t - 1 ] ; }
                if ( t < st[ sr ] ) { add = ( 1LL * add * dp[ t ][ st[ sr ] - 1 ] ) % MOD ; }
                aux1 += add ;
                if ( aux1 >= MOD ) { aux1 -= MOD ; }
            }
            for ( int t = en[ sr ] ; t <= r ; ++ t ) {
                int add = 1 ;
                if ( t < r ) { add = dp[ t + 1 ][ r ] ; }
                if ( en[ sr ] < t ) { add = ( 1LL * add * dp[ en[ sr ] + 1 ][ t ] ) % MOD ; }
                aux2 += add ;
                if ( aux2 >= MOD ) { aux2 -= MOD ; }
            }
            dp[ l ][ r ] = coef ;
            dp[ l ][ r ] = ( 1LL * dp[ l ][ r ] * ( ( 1LL * aux1 * aux2 ) % MOD ) ) % MOD ;
        }
    }
    
    printf ( "%d\n" , dp[ 1 ][ n ] ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}