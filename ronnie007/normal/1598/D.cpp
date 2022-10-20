#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
pair < int , int > a[ MAXN ] ;
vector < int > comp1[ MAXN ] ;
vector < int > comp2[ MAXN ] ;



class Tree {
public :
    int lval[ 4 * MAXN ] ;
    int rval[ 4 * MAXN ] ;
    long long sm[ 4 * MAXN ] ;
    void unite ( int where ) {
        lval[ where ] = lval[ 2 * where ] + lval[ 2 * where + 1 ] ;
        rval[ where ] = rval[ 2 * where ] + rval[ 2 * where + 1 ] ;
        sm[ where ] = sm[ 2 * where ] + sm[ 2 * where + 1 ] ;
    }
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            rval[ where ] = (int)comp1[ IL ].size ( ) ;
            lval[ where ] = sm[ where ] = 0 ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        unite ( where ) ;
    }
    void update ( int where , int IL , int IR , int pos , int chl , int chr ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            lval[ where ] += chl ;
            rval[ where ] += chr ;
            sm[ where ] = 1LL * lval[ where ] * rval[ where ] ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , chl , chr ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , chl , chr ) ;
        }
        unite ( where ) ;
    }
    pair < int , int > get ( int where , int IL , int IR , int pos ) {
        if ( IL == IR ) {
            return { lval[ where ] , rval[ where ] } ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            return get ( 2 * where , IL , mid , pos ) ;
        }
        else {
            return get ( 2 * where + 1 , mid + 1 , IR , pos ) ;
        }
    }
};

Tree w ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        comp1[ i ].clear ( ) ;
        comp2[ i ].clear ( ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ].first >> a[ i ].second ;
        comp1[ a[ i ].first ].push_back ( a[ i ].second ) ;
        comp2[ a[ i ].second ].push_back ( a[ i ].first ) ;
    }
}

void solve ( ) {
    long long ans = 0 ;
    long long lft = n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int aux = (int)comp1[ i ].size ( ) ;
        lft -= aux ;
        ans += 1LL * aux * lft * ( n - aux - lft ) ;
    }
    w.init ( 1 , 1 , n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( auto x : comp2[ i ] ) {
            w.update ( 1 , 1 , n , x , 0 , -1 ) ;
        }
        for ( auto x : comp2[ i ] ) {
            ans += w.sm[ 1 ] ;
            pair < int , int > aux = w.get ( 1 , 1 , n , x ) ;
            ans += 1LL * aux.first * ( w.rval[ 1 ] - aux.second ) ;
            ans += 1LL * aux.second * ( w.lval[ 1 ] - aux.first ) ;
        }

        for ( auto x : comp2[ i ] ) {
            w.update ( 1 , 1 , n , x , 1 , 0 ) ;
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}