#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

#define INF  1000000100

struct range {
    int x, y;
    };
struct range prev[ 100007 ] , cur[ 100007 ] , blocked[ 100007 ] ;

bool comp1 ( range A , range B ) {
    if ( A.x == B.x )
        return A.y < B.y ;
    return A.x < B.x ;
    }

int main() {
    int n , m ;
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 1 ; i <= m ; i ++ ) {
        int xx , yy ;
        scanf ( "%d%d" , &xx , &yy ) ;
        blocked[ i ].x = xx ;
        blocked[ i ].y = yy ;
        }

    sort ( blocked + 1 , blocked + m + 1 , comp1 ) ;
    int curCnt = 0 , prevCnt = 1 ;
    prev[ prevCnt ].x = prev[ prevCnt ].y = 1 ;

    int k ;
    for ( i = 1 ; i <= m ; i ++ ) {
        if ( blocked[ i ].x != blocked[ i - 1 ].x + 1 ) {
            prevCnt = 1 ;
            prev[ 1 ].y = n ;
            }

        int j ;
        for ( j = i ; j <= m && blocked[ j ].x == blocked[ i ].x ; j ++ ) ;
        j -- ;
        curCnt = 0 ;
        int leftSegment = 1 ;
        for ( k = i ; k <= j ; k ++ ) {
            if ( blocked[ k ].y - 1 >= leftSegment ) {
                cur[ ++curCnt ].x = leftSegment ;
                cur[ curCnt ].y = blocked[ k ].y - 1 ;
                }
            leftSegment = blocked[ k ].y + 1 ;
            }
        if ( leftSegment <= n ) {
            cur[ ++curCnt ].x = leftSegment ;
            cur[ curCnt ].y = n ;
            }

        for ( k = 1 ; k <= curCnt ; k ++  ) {
            int left = 1 , right = prevCnt , ret = -1 ;
            int mid ;
            while ( left <= right ) {
                mid = ( left + right ) / 2 ;
                if ( prev[ mid ].y >= cur[ k ].x ) {
                    ret = prev[ mid ].x ;
                    right = mid - 1 ;
                    }
                else
                    left = mid + 1;
                }
            if ( ret == -1 || ret > cur[ k ].y )
                cur[ k ].x = cur[ k ].y = INF ;
            else
                cur[ k ].x = max( ret , cur[ k ].x ) ;
            }

        prevCnt = 0 ;
        for ( k = 1 ; k <= curCnt ; k ++ )
            if ( cur[ k ].x != INF && cur[ k ].y != INF )
                prev[ ++prevCnt ] = cur[ k ];
        if ( prevCnt == 0 ) {
            printf("-1") ;
            return 0 ;
            }
        i = j ;
        }

    if (blocked[ m ].x != n ) {
        prevCnt = 1;
        prev[1].y = n ;
        }

    if ( prev[ prevCnt ].y == n )
        printf ( "%d\n", 2 * n - 2 ) ;
    else
        printf ( "-1" ) ;
    return 0 ;
    }