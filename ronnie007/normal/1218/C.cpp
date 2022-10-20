#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
using namespace std ;


#define MAXN 507

int n , m , k ;

struct enemy {
    int st ;
    int pos ;
    int dist ;
    int diff ;
    enemy ( ) {
        st = pos = dist = diff = 0 ;
    }
    enemy ( int _st , int _pos , int _dist , int _diff ) {
        st = _st , pos = _pos , dist = _dist , diff = _diff ;
    }
    bool operator < ( enemy other ) const {
        return ( dist < other.dist ) ;
    }
};

vector < enemy > v[ MAXN ][ MAXN ] ;
int sz[ MAXN ][ MAXN ] ;

long long dp[ 2 ][ MAXN ][ MAXN ][ 2 ] ;

long long init[ MAXN ][ MAXN ] ;


long long get_init ( int x , int y ) {
    long long ret = 0 ;
    int tm = x + y - 2 ;
    for ( int i = 0 ; i < sz[ x ][ y ] ; ++ i ) {
        if ( tm < v[ x ][ y ][ i ].st ) { continue ; }
        if ( ( tm - v[ x ][ y ][ i ].st ) % 4 == v[ x ][ y ][ i ].pos - 1 ) {
            ret += v[ x ][ y ][ i ].diff ;
        }
    }
    return ret ;
}

long long calc ( int x , int y , int lst , int dir ) {
    long long ret = init[ x ][ y ] ;
    int tm = x + y - 2 ;
    for ( int i = 0 ; i < sz[ x ][ y ] ; ++ i ) {
        if ( lst < v[ x ][ y ][ i ].dist ) { return ret ; }        
        if ( tm < v[ x ][ y ][ i ].st ) { continue ; }
        if ( ( tm - v[ x ][ y ][ i ].st ) % 4 == v[ x ][ y ][ i ].pos - 1 ) {
            if ( v[ x ][ y ][ i ].pos == 3 ) {
                if ( dir == 0 && lst >= v[ x ][ y ][ i ].dist ) {
                    int aux = tm - v[ x ][ y ][ i ].dist ;
                    if ( aux >= v[ x ][ y ][ i ].st && ( ( aux - v[ x ][ y ][ i ].st ) % 4 ) == 1 ) {
                        ret -= v[ x ][ y ][ i ].diff ;                        
                    }
                }
                if ( dir == 1 && lst >= v[ x ][ y ][ i ].dist ) {
                    int aux = tm - v[ x ][ y ][ i ].dist ;
                    if ( aux >= v[ x ][ y ][ i ].st && ( ( aux - v[ x ][ y ][ i ].st ) % 4 ) == 0 ) {
                        ret -= v[ x ][ y ][ i ].diff ;
                    }
                }
            }
            if ( v[ x ][ y ][ i ].pos == 4 ) {
                if ( dir == 0 && lst >= v[ x ][ y ][ i ].dist ) {
                    int aux = tm - v[ x ][ y ][ i ].dist ;
                    if ( aux >= v[ x ][ y ][ i ].st && ( ( aux - v[ x ][ y ][ i ].st ) % 4 ) == 0 ) {
                        ret -= v[ x ][ y ][ i ].diff ;                        
                    }
                }
            }
        }
    }
    return ret ;
}

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &k ) ;
    for ( int i = 1 ; i <= k ; ++ i ) {
        int x , y , st , dist , diff ;
        scanf ( "%d%d%d%d%d" , &x,  &y , &dist , &st , &diff ) ;
        ++ x , ++ y ;
        if ( x + y - 2 >= st ) {
            v[ x ][ y ].push_back ( enemy ( st , 1 , dist , diff ) ) ;
        }
        if ( x + y - 2 >= st ) {
            v[ x + dist ][ y - dist ].push_back ( enemy ( st , 2 , dist , diff ) ) ;
        }
        if ( x + dist + y - 2 >= st ) {
            v[ x + dist ][ y ].push_back ( enemy ( st , 3 , dist , diff ) ) ;
        }
        if ( x + y + dist - 2 >= st ) {
            v[ x ][ y + dist ].push_back ( enemy ( st , 4 , dist , diff ) ) ;
        }
    }
}

void solve ( ) {
    int prv , nxt ;
    prv = 0 , nxt = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            sz[ i ][ j ] = v[ i ][ j ].size ( ) ;
            sort ( v[ i ][ j ].begin ( ) , v[ i ][ j ].end ( ) ) ;
            init[ i ][ j ] = get_init ( i , j ) ;
        }
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        for ( int j = 0 ; j < MAXN ; ++ j ) {
            for ( int t = 0 ; t < 2 ; ++ t ) {
                dp[ prv ][ i ][ j ][ t ] = -1 ;
                dp[ nxt ][ i ][ j ][ t ] = -1 ;
            }
        }
    }
    dp[ prv ][ 1 ][ 0 ][ 0 ] = dp[ prv ][ 1 ][ 0 ][ 1 ] = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            // arg = 0
            for ( int t = 0 ; t < j ; ++ t ) {
                if ( dp[ prv ][ j ][ t ][ 0 ] == -1 ) { continue ; }
                // move right
                if ( j < m ) {
                    long long aux = dp[ prv ][ j ][ t ][ 0 ] + calc ( i , j + 1 , t + 1 , 0 ) ;
                    if ( dp[ prv ][ j + 1 ][ t + 1 ][ 0 ] == -1 ) { dp[ prv ][ j + 1 ][ t + 1 ][ 0 ] = aux ; }
                    dp[ prv ][ j + 1 ][ t + 1 ][ 0 ] = min ( dp[ prv ][ j + 1 ][ t + 1 ][ 0 ] , aux ) ;
                }
                // move down
                if ( i < n ) {
                    long long aux = dp[ prv ][ j ][ t ][ 0 ] + calc ( i + 1 , j , 1 , 1 ) ;
                    if ( dp[ nxt ][ j ][ 1 ][ 1 ] == -1 ) { dp[ nxt ][ j ][ 1 ][ 1 ] = aux ; }
                    dp[ nxt ][ j ][ 1 ][ 1 ] = min ( dp[ nxt ][ j ][ 1 ][ 1 ] , aux ) ;
                }
            }
            // arg = 1
            for ( int t = 0 ; t < i ; ++ t ) {
                if ( dp[ prv ][ j ][ t ][ 1 ] == -1 ) { continue ; }
                // move right
                if ( j < m ) {
                    long long aux = dp[ prv ][ j ][ t ][ 1 ] + calc ( i , j + 1 , 1 , 0 ) ;
                    if ( dp[ prv ][ j + 1 ][ 1 ][ 0 ] == -1 ) { dp[ prv ][ j + 1 ][ 1 ][ 0 ] = aux ; }
                    dp[ prv ][ j + 1 ][ 1 ][ 0 ] = min ( dp[ prv ][ j + 1 ][ 1 ][ 0 ] , aux ) ;
                }
                // move down
                if ( i < n ) {
                    long long aux = dp[ prv ][ j ][ t ][ 1 ] + calc ( i + 1 , j , t + 1 , 1 ) ;
                    if ( dp[ nxt ][ j ][ t + 1 ][ 1 ] == -1 ) { dp[ nxt ][ j ][ t + 1 ][ 1 ] = aux ; }
                    dp[ nxt ][ j ][ t + 1 ][ 1 ] = min ( dp[ nxt ][ j ][ t + 1 ][ 1 ] , aux ) ;
                }
            }
        }
        if ( i == n ) { break ; }
        prv ^= 1 , nxt ^= 1 ;
        for ( int j = 0 ; j <= m ; ++ j ) {
            for ( int t = 0 ; t < MAXN ; ++ t ) {
                dp[ nxt ][ j ][ t ][ 0 ] = dp[ nxt ][ j ][ t ][ 1 ] = -1 ;
            }
        }
    }
    long long ans = -1 ;
    for ( int i = 0 ; i < MAXN ; ++ i ) {
        for ( int j = 0 ; j < 2 ; ++ j ) {
            if ( dp[ prv ][ m ][ i ][ j ] == -1 ) { continue ; }
            if ( ans == -1 ) { ans = dp[ prv ][ m ][ i ][ j ] ; }
            ans = min ( ans , dp[ prv ][ m ][ i ][ j ] ) ;
        }
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