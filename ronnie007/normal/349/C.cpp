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

int n ;
int a[ 300007 ] ;
int b[ 300007 ] ;

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
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        }
    sort ( a , a + n ) ;
    }

void solve ( )
    {
    long long  ans = 0 ;
    int i ;
    int p ;
    for ( i = 0 ; i < n - 1 ; i ++ )
        {
        ans += a[ n - 1 ] - a[ i ] ;
        }
    p = ans ;
    if ( ans < a[ n - 1 ] )
        {
        ans = ( a[ n - 1 ] ) + ( a[ n - 1 ] - p ) / ( n - 1 )   ;
        if ( ( a[ n - 1 ] - p ) % ( n - 1 ) != 0 ) ans ++ ;
        }
    else ans = a[ n - 1 ] ;
    printf ( "%I64d\n" , ans  ) ;
    }