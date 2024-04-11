#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<string>
#include<map>
#include<vector>
#include<queue>
using namespace std;

#define inf 1000000007

struct tuhla {
    int vertex ;
    int cost ;
};

bool operator < ( struct tuhla p1 , struct tuhla p2 ) {
    return (p1.cost>p2.cost) ;
}

int n , m , k ;
int d[ 507 ][ 507 ] ;
int c[ 507 ] ;
int st[ 507 ] ;
int dist[ 100007 ] ;

int t[ 100007 ] ;
int used[ 100007 ] ;

vector < struct tuhla > v[ 100007 ] ;


void dfs ( int vertex ) {
    used[ vertex ] = 1 ;
    int i ;
    int sz = v[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ].cost == 0 && used[ v[ vertex ][ i ].vertex ] == 0 ) {
            dfs ( v[ vertex ][ i ].vertex ) ;
        }
    }
}

void dijkstra ( int type ) {
    //cout << "--------\n" ;
    int i , j , sz ;
    for ( i = 1 ; i <= n ; i ++ )  { used[ i ] = 0 ; dist[ i ] = inf ; d[ type ][ t[ i ] ] = inf ; }
    priority_queue < struct tuhla > q ;
    while ( q.empty ( ) == false ) q.pop ( ) ;
    i = st[ type ] ;
    used[ i ] = 1 ;
    struct tuhla u , w ;
    while ( i <= n && t[ i ] == type ) {
        u.cost = 0 ;
        u.vertex = i ;
        dist[ i ] = 0 ;
        q.push ( u ) ;
        i ++ ;
    }
    while ( q.empty ( ) == false ) {
        u = q.top ( ) ;
        q.pop ( ) ;
        //cout << u.cost << "\n" ;
        if ( u.cost != dist[ u.vertex ] ) continue ;
        sz = v[ u.vertex ].size ( ) ;
        for ( i = 0 ; i < sz ; i ++ ) {
            //printf ( "%d\n" , v[ u.vertex ][ i ].vertex ) ;
            if ( dist[ v[ u.vertex ][ i ].vertex ] >= u.cost + v[ u.vertex ][ i ].cost ) {
                //printf ( "%d\n" , v[ u.vertex ][ i ].vertex ) ;
                if ( dist[ v[ u.vertex ][ i ].vertex ] == u.cost + v[ u.vertex ][ i ].cost ) {
                    //if ( t[ v[ u.vertex ][ i ].vertex ] != type ) { d[ type ][ t[ v[ u.vertex ][ i ].vertex ] ] = min ( d[ type ][ t[ v[ u.vertex ][ i ].vertex ] ] , u.cost + v[ u.vertex ][ i ].cost  ) ; }
                    //if ( t[ v[ u.vertex ][ i ].vertex ] == type ) {
                        //if ( u.cost + v[ u.vertex ][ i ].cost == 0 ) used[ v[ u.vertex ][ i ].vertex ] = 1 ;
                    //}
                }
                else {
                    dist[ v[ u.vertex ][ i ].vertex ] = u.cost + v[ u.vertex ][ i ].cost ;
                    if (  t[ v[ u.vertex ][ i ].vertex ] != type ) d[ type ][ t[ v[ u.vertex ][ i ].vertex ] ] = min ( d[ type ][ t[ v[ u.vertex ][ i ].vertex ] ] , u.cost + v[ u.vertex ][ i ].cost  ) ;
                    //if ( t[ v[ u.vertex ][ i ].vertex ] == type && u.cost + v[ u.vertex ][ i ].cost == 0 ) used[ v[ u.vertex ][ i ].vertex ] = 1 ;
                    w.vertex = v[ u.vertex ][ i ].vertex ;
                    w.cost = u.cost + v[ u.vertex ][ i ].cost ;
                    q.push ( w ) ;
                }
            }
        }
    }
    //for ( i = 1 ; i <= n ; i ++ ) {
    //  printf ( "%d\n" , dist[ i ] ) ;
    //}
}

void input ( ) ;
void solve ( ) ;



int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    scanf ( "%d%d%d"  , &n , &m , &k ) ;
    int i , j ;
    int x , y , z ;
    struct tuhla u ;
    int pos = 0 ;
    for ( i = 1 ; i <= k ; i ++ ) {
        scanf ( "%d" , &c[ i ] ) ;
        st[ i ] = pos + 1 ;
        pos += c[ i ] ;
        for ( j = 0 ; j < c[ i ] ; j ++ ) {
            t[ j + st[ i ] ] = i ;
        }
    }
    for ( i = 0 ; i < m ; i ++ ) {
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        u.vertex = y ;
        u.cost = z ;
        v[ x ].push_back ( u ) ;
        u.vertex = x ;
        v[ y ].push_back ( u ) ;
    }
}

void solve ( ) {
    int i , j ;
    for ( i = 1 ; i <= k ; i ++ ) {
        dfs ( st[ i ] ) ;
        for ( j = st[ i ] + 1 ; j <= n ; j ++ ) {
            if ( t[ j ] != i ) break ;
            if ( used[ j ] == 0 ) break ;
        }

        if ( t[ j ] == i ) {
            printf ( "No\n" ) ;
            return ;
        }
        for ( j = 1 ; j <= n ; j ++ ) used[ j ] = 0 ;
    }
    for ( i = 1 ; i <= k ; i ++ ) {
        dijkstra ( i ) ;
    }
    /*
    for ( i = 0 ; i < k ; i ++ ) {
        for ( j = 0 ; j < k ; j ++ ) {
            printf ( "%d " , d[ i ][ j ] ) ;
        }
        printf ( "\n" ) ;
    }
    */
    //
    for ( i = 1 ; i <= k ; i ++ ) {
        d[ i ][ i ] = 0 ;
    }
    printf ( "Yes\n" ) ;
    for ( i = 1 ; i <= k ; i ++ ) {
        for ( j = 1 ; j <= k ; j ++ ) {
            if ( d[ i ][ j ] != inf )printf ( "%d " , d[ i ][ j ] ) ;
            else printf ( "-1 "  ) ;
        }
        printf ( "\n" ) ;
    }
}