#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std ;


int n , m ;
int b[ 100007 ] ;

struct rebro
    {
    int where ;
    int d ;
    };

vector < struct rebro > v[ 100007 ] ;

struct tuhla
    {
    int where ;
    int dist ;
    } ;

bool operator < ( struct tuhla p1 , struct tuhla p2 )
    {
    return p1.dist >= p2.dist ;
    }


priority_queue < struct tuhla > q ;



vector < int > t[ 100007 ] ;

void input ( ) ;
void solve ( ) ;
int get( struct tuhla p1 ) ;


int main ( )
    {
    input ( ) ;
    solve ( ) ;
    return 0 ;
    }


void input ( )
    {
    int i , j ;
    scanf ( "%d%d" , &n ,&m ) ;
    int x , y , z ;
    struct rebro p1 ;
    for ( i = 0 ; i < m ; i ++ )
        {
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        p1.where = y ;
        p1.d = z ;
        v[ x ].push_back ( p1 ) ;
        p1.where = x ;
        v[ y ].push_back ( p1 ) ;
        }
    for ( i = 1 ;  i <= n ; i ++ )
        {
        scanf ( "%d" , &x ) ;
        t[ i ].resize ( x ) ;
        for ( j = 0 ; j < x ; j ++ )
            {
            scanf ( "%d" , &t[ i ][ j ] ) ;
            }
        }
    }

int get( struct tuhla p1 )
    {
    int l , r ;
    l = 0 ;
    r = t[ p1.where ].size ( ) - 1 ;
    if ( r == -1 ) return 0 ;
    if ( r == 0 )
        {
        if ( t[ p1.where ][ r ] == p1.dist ) return 1 ;
        return 0 ;
        }
    int mid ;
    int ans = 0 ;
    while ( r - l > 1 )
        {
        ///cout << l << " " << r << "\n" ;
        mid = ( r + l ) / 2 ;
        if ( t[ p1.where ][ mid ] <= p1.dist ) l = mid ;
        else r = mid ;
        }
    ///cout << "here\n" ;
    ///cout << l << " " << r << "\n" ;
    if ( t[ p1.where ][ r ] == p1.dist && t[ p1.where ][ l ] < p1.dist ) l ++ ;
    int i ;
    if ( l == t[ p1.where ].size ( ) ) return 0 ;
    if ( t[ p1.where ][ l ] != p1.dist ) return 0 ;
    ans = 1 ;
    int l1 = l + 1 , r1 = t[ p1.where ].size ( ) - 1 ;
    while ( r1 - l1 > 1 )
        {
        ///if ( p1.where == 1 ) cout << l1 << " " << r1 << "\n" ;
        mid = ( r1 + l1 ) / 2 ;
        if ( t[ p1.where ][ mid ] - t[ p1.where ][ l ] == mid - l ) l1 = mid ;
        else r1 = mid ;
        }
    if ( t[ p1.where ][ r1 ] - t[ p1.where ][ l ] == r1 - l && l1 != t[ p1.where ].size ( ) - 1 ) l1 ++ ;
    ans = l1 - l + 1 ;
    ///if ( p1.where == 1 ) cout << ans << "\n" ;
    /**
    for ( i = l + 1 ; i < t[ p1.where ].size ( )  ; i ++ )
        {
        if ( t[ p1.where ][ i ] == t[ p1.where ][ i - 1 ] + 1 ) ans ++ ;
        else break ;
        }
    **/
    return ans ;
    }

void solve ( )
    {
    struct tuhla cur ;
    struct tuhla p1 ;
    p1.where = 1 ;
    p1.dist = 0 ;
    q.push( p1 ) ;
    ///p1.dist = get( p ) ;
    int i ;
    int sz ;
    for ( i = 0 ; i <= n ; i ++ )
        {
        b[ i ] = 1000100007 ;
        }
    b[ 1 ] = 0 ;
    int vertex ;
    int need ;
    while ( q.empty ( ) == false )
        {
        cur = q.top( ) ;
        q.pop ( ) ;
        vertex = cur.where ;
        sz = v[ vertex  ].size ( ) ;
        for ( i = 0 ; i < sz ; i ++ )
            {
            need = v[ vertex ][ i ].d + cur.dist ;
            p1.where = vertex ;
            p1.dist = cur.dist ;
            ///cout << need << "\n" ;
            if ( b[ v[ vertex ][ i ].where ] > need ) need += get ( p1 ) ;
            ///cout << need << "\n" ;
            if ( b[ v[ vertex ][ i ].where ] > need )
                {
                ///cout << v[ vertex ][ i ].where << "\n"  ;
                b[ v[ vertex ][ i ].where ] = need ;
                p1.where = v[ vertex ][ i ].where ;
                p1.dist = need ;
                q.push ( p1 ) ;
                }
            }
        }
    ///cout << b[ 2 ] << "\n" ;
    if ( b[ n ] == 1000100007 ) printf ( "-1\n" ) ;
    else printf ( "%d\n" , b[ n ] ) ;
    }