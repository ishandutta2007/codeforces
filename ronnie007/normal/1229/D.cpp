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


#define MAXN 200007

int n , k ;
int a[ MAXN ][ 7 ] ;

int code[ MAXN ] ;

int nxt[ MAXN ][ 127 ] ;
int lst[ 127 ] ;
int fac[ 7 ] ;
bool vis[ 127 ] ;
int st_position[ 127 ] ;

int transition[ 127 ][ 127 ] ;

vector < int > precalc[ 127 ] ;

int encode ( vector < int > v ) {
    int ret = 0 ;
    bool used[ 7 ] ;
    for ( int i = 0 ; i <= k ; ++ i ) { used[ i ] = false ; }
    for ( int i = 0 ; i < k ; ++ i ) {
        int cnt = 0 ;
        for ( int j = 1 ; j < v[ i ] ; ++ j ) {
            if ( used[ j ] == false ) { ++ cnt ; }
        }
        ret += cnt * fac[ k - i - 1 ] ;
        used[ v[ i ] ] = true ;
    }
    return ret ;
}

vector < int > decode ( int x ) {
    vector < int > ret ;
    ret.resize ( k ) ;
    bool used[ 7 ] ;
    for ( int i = 0 ; i <= k ; ++ i ) { used[ i ] = false ; }
    for ( int i = 0 ; i < k ; ++ i ) {
        int hh = ( x / fac[ k - i - 1 ] ) ;
        x %= fac[ k - i - 1 ] ;
        for ( int j = 1 ; j <= k ; ++ j ) {
            if ( used[ j ] == false ) {
                if ( hh == 0 ) { ret[ i ] = j ; used[ j ] = true ; break ; }
                -- hh ;
            }
        }
    }
    return ret ;
}

vector < int > shift ( vector < int > st , vector < int > aux ) {
    vector < int > ret = st ;
    for ( int i = 0 ; i < k ; ++ i ) {
        ret[ i ] = st[ aux[ i ] - 1 ] ;
    }
    return ret ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    fac[ 0 ] = 1 ;
    for ( int i = 1 ; i <= k ; ++ i ) {
        fac[ i ] = ( fac[ i - 1 ] * i ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= k ; ++ j ) {
            scanf ( "%d" , &a[ i ][ j ] ) ;
        }
        vector < int > aux ;
        for ( int j = 0 ; j < k ; ++ j ) { aux.push_back ( a[ i ][ j + 1 ] ) ; }
        code[ i ] = encode ( aux ) ;
    }
    for ( int i = n ; i >= 1 ; -- i ) {
        lst[ code[ i ] ] = i ;
        for ( int j = 0 ; j < fac[ k ] ; ++ j ) {
            nxt[ i ][ j ] = lst[ j ] ;
        }
    }
    for ( int i = 0 ; i < fac[ k ] ; ++ i ) {
        precalc[ i ] = decode ( i ) ;
    }
    for ( int i = 0 ; i < fac[ k ] ; ++ i ) {
        for ( int j = 0 ; j < fac[ k ] ; ++ j ) {
            transition[ i ][ j ] = encode ( shift ( precalc[ i ] , precalc[ j ] ) ) ;
        }
    }
}

void solve ( ) {
    long long ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        vector < int > v ;
        for ( int j = 0 ; j < fac[ k ] ; ++ j ) {
            vis[ j ] = false ;
            st_position[ j ] = 0 ;
            if ( nxt[ i ][ j ] != 0 ) {
                v.push_back ( nxt[ i ][ j ] ) ;
            }
        }
        vis[ 0 ] = true ;
        sort ( v.begin ( ) , v.end ( ) ) ;
        int sz = v.size ( ) ;
        int cnt = 1 ;
        int lst = i - 1 ;
        vector < int > added ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            if ( vis[ code[ v[ j ] ] ] == true ) { continue ; }
            int old = cnt ;
            added.push_back ( v[ j ] ) ;
            queue < int > q ;
            for ( int t = 0 ; t < fac[ k ] ; ++ t ) {
                if ( vis[ t ] == true ) { q.push ( t ) ; }

            }
            int sz = added.size ( ) ;
            while ( q.empty ( ) == false ) {
                int x = q.front ( ) ;
                q.pop ( ) ;
                for ( int t = st_position[ x ] ; t < sz ; ++ t ) {
                    int id = transition[ x ][ code[ added[ t ] ] ] ;
                    if ( vis[ id ] == false ) { ++ cnt ; q.push ( id ) ; vis[ id ] = true ; }
                    ++ st_position[ x ] ;
                }
            }
            ans += old * ( v[ j ] - lst - 1 ) ;
            lst = v[ j ] - 1 ;
        }
        ans += ( n - lst ) * cnt ;
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