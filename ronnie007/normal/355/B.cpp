#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
using namespace std ;

int c1 , c2 , c3 , c4 ;
int n , m ;
int a[ 1007 ] ;
int b[ 1007 ] ;
int times1[ 1007 ] ;
int times2[ 1007 ] ;
int sm1 = 0 ;
int sm2 = 0 ;

void input ( ) ;
void solve ( ) ;


int main ( )
    {
    input ( ) ;
    solve ( ) ;
    return 0 ;
    }


void input ( )
    {
    scanf ( "%d%d%d%d" , &c1 , &c2 , &c3 , &c4  ) ;
    int i ;
    scanf ( "%d%d" , &n , &m ) ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        sm1 += a[ i ] ;
        }
    for ( i = 0 ; i < m ; i ++ )
        {
        scanf ( "%d" , &b[ i ] ) ;
        sm2 += b[ i ] ;
        }
    }

void solve ( )
    {
    int ans = c4 ;

    int s = 0 ;
    int s1 = 0 ;
    int i ;
    for ( i = 0 ; i < n ; i ++ )
        {
        if ( a[ i ] * c1 < c2 )
            {
            s += a[ i ] * c1 ;
            }
        else s += c2 ;
        ///cout << s << "\n" ;
        }

    for ( i = 0 ; i < m ; i ++ )
        {
        if ( b[ i ] * c1 < c2 )
            {
            s1 += b[ i ]  * c1 ;
            }
        else s1 += c2 ;
        }
    if ( s > c3 ) s = c3 ;
    if ( s1 > c3 ) s1 = c3 ;
    if ( ans > s + s1 ) ans = s + s1 ;
    printf ( "%d\n" , ans ) ;
    }