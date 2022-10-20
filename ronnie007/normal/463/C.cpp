#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
using namespace std ;

int n ;
int a[ 2007 ][ 2007 ] ;
// sum(x,y)
long long br1[ 10007 ] ;
// minus(x,y)
long long br2[ 10007 ] ;

void input ( ) ;
void solve ( ) ;



int main ( )  {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    scanf ( "%d" , &n ) ;
    int i , j ;
    int x , y ; 
    int df ;
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 1 ; j <= n ; j ++ ) {
            scanf ( "%d" , &a[ i ][ j ] ) ;
            x = i + j ;
            y = i - j ;
            if ( y < 0 ) { df = 4000 ; y = (-y) ; }
            else df = 0 ;
            br1[ x ] += a[ i ][ j ] ;
            br2[ df + y ] += a[ i ][ j ] ; 
        }
    }
}

void solve ( ) {
    int x , y ; 
    long long ans = 0 ;
    int i , j ;
    int px = -1 , py = -1 ;
    int qx = -1 , qy = -1 ;
    long long cur1 = -1 ;
    long long cur2 = -1 ;
    int df = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 1 ; j <= n ; j ++ ) {
            x = i + j ;
            y = i - j ;
            if ( y < 0 ) { df = 4000 ; y = (-y); }
            else df = 0 ;

            if ( ( ( i + j ) % 2)  == 0 ) {
                if ( cur1 < ( br1[ x ] + br2[ df + y ] - a[ i ][ j ] ) ) {
                    cur1 = ( br1[ x ] + br2[ df + y ] - a[ i ][ j ] ) ;
                    px = i ;
                    py = j ; 
                }
            }
            else {
                if ( cur2 < ( br1[ x ] + br2[ df + y ] - a[ i ][ j ] ) ) {
                    cur2 = ( br1[ x ] + br2[ df + y ] - a[ i ][ j ] ) ;
                    qx = i ;
                    qy = j ; 
                }
            }
        }
    }
    //printf ( "%I64d %I64d\n" , cur1 , cur2 ) ;
    ans = cur1 + cur2 ; 
    printf ( "%I64d\n" , ans ) ;
    printf ( "%d %d %d %d\n" , px , py , qx , qy ) ;
}