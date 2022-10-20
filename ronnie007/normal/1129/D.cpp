#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<stack>
#include<ctime>
#include<set>
using namespace std ;

#define MAXN 100007
#define MOD 998244353
#define MAGIC 300

int n , k ;
int a[ MAXN ] ;

long long dp[ MAXN ] ;

int prv1[ MAXN ] ;
int prv2[ MAXN ] ;

class bucket {
    public :
    int st , en ;
    long long pref[ MAGIC + 2 ] ;
    int val[ MAGIC + 2 ] ;
    int mn = 0 ;
    void recalc ( ) {
        int curr = val[ 0 ] ;
        for ( int i = st ; i <= en ; ++ i ) {
            curr = ( curr < val[ i - st ] ) ? curr : val[ i - st ] ;
        }
        mn += curr ;
        for ( int i = st ; i <= en ; ++ i ) {
            val[ i - st ] -= curr ;
        }
        for ( int i = 0 ; i <= MAGIC ; ++ i ) { pref[ i ] = 0 ; }
        for ( int i = st ; i <= en ; ++ i ) {
            pref[ val[ i - st ] ] = pref[ val[ i - st ] ] + ( ( i > 0 ) ? dp[ i - 1 ] : 1 ) ;
            if ( pref[ val[ i - st ] ] >= MOD ) { pref[ val[ i - st ] ] -= MOD ; }
        }
        for ( int i = 1 ; i <= MAGIC ; ++ i ) {
            pref[ i ] += pref[ i - 1 ] ;
            if ( pref[ i ] >= MOD ) { pref[ i ] -= MOD ; }
        }
    }
    void update ( int add ) {
        mn += add ;
    }
    long long ask ( ) {
        if ( mn > k ) { return 0 ; }
        int id = ( k - mn ) ;
        if ( id > MAGIC ) { id = MAGIC ; }
        return pref[ id ] ;
    }
};
bucket f[ 2 * MAGIC ] ;
int NUM_BUCKETS ;

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        prv1[ a[ i ] ] = prv2[ a[ i ] ] = -1 ;
    }
    NUM_BUCKETS = ( n / MAGIC ) + ( ( n % MAGIC ) != 0 ) ;
    for ( int i = 0 ; i < NUM_BUCKETS ; ++ i ) {
        f[ i ].st = i * MAGIC ;
        f[ i ].en = min ( f[ i ].st + MAGIC - 1 , n - 1 ) ;
    }
}


void upd_int ( int st , int en , int val ) {
    if ( en < st ) { return ; }
    if ( en - st <= MAGIC ) {
        for ( int i = st ; i <= en ; ++ i ) {
            int id = ( i / MAGIC ) ;
            f[ id ].val[ i - f[ id ].st ] += val ;
        }
        f[ ( st / MAGIC ) ].recalc ( ) ;
        for ( int i = st + 1 ; i <= en ; ++ i ) {
            if ( ( i / MAGIC ) != ( ( i - 1 ) / MAGIC ) ) {
                f[ ( i / MAGIC ) ].recalc ( ) ;
            }
        }
        return ;
    }
    for ( int i = st ; i <= en ; ++ i ) {
        if ( ( i / MAGIC ) != ( st / MAGIC ) ) { break ; }
        int id = ( i / MAGIC ) ;
        f[ id ].val[ i - f[ id ].st ] += val ;
    }
    f[ ( st / MAGIC ) ].recalc ( ) ;
    for ( int i = en ; i >= st ; -- i ) {
        if ( ( i / MAGIC ) != ( en / MAGIC ) ) { break ; }
        int id = ( i / MAGIC ) ;
        f[ id ].val[ i - f[ id ].st ] += val ;
    }
    f[ ( en / MAGIC ) ].recalc ( ) ;
    for ( int i = ( st / MAGIC ) + 1 ; i < ( en / MAGIC ) ; ++ i ) {
        f[ i ].update ( val ) ;
    }
}

void solve ( ) {
    for ( int i = 0 ; i < n ; ++ i ) {
        upd_int ( prv2[ a[ i ] ] + 1 , prv1[ a[ i ] ] , -1 ) ;
        prv2[ a[ i ] ] = prv1[ a[ i ] ] ;
        upd_int ( prv1[ a[ i ] ] + 1 , i , 1 ) ;
        prv1[ a[ i ] ] = i ;
        for ( int j = 0 ; j <= ( i / MAGIC ) ; ++ j ) {
            dp[ i ] += f[ j ].ask ( ) ;
            dp[ i ] = ( dp[ i ] < MOD ) ? dp[ i ] : dp[ i ] - MOD ;
        }
    }
    printf ( "%I64d\n" , dp[ n - 1 ] ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}