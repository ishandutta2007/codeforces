#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<map>
using namespace std;


int n ;
pair < int , int > a[ 300007 ] ;
int ans[ 300007 ] ;

void input ( ) ;
void solve ( ) ;


int main()
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
        scanf ( "%d" , &a[ i ].first  ) ;
        a[ i ].second = i ;
        }
    sort ( a , a + n ) ;
    }

void solve ( )
    {
    int i ;
    int mn = a[ 0 ].first + 1 ;
    ans[ a[ 0 ].second ] = mn - 1  ;
    for ( i = 1 ; i < n ; i ++ )
        {
        if ( mn < a[ i ].first ) mn = a[ i ].first ;
        ans[ a[ i ].second ] =  mn ;
        mn ++ ;
        }
    for ( i = 0 ; i < n ; i ++ )
        {
        printf ( "%d " , ans[ i ] ) ;
        }
    printf ( "\n" ) ;
    }