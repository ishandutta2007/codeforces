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
int a[ 100007 ] ;
int d[ 100007 ] ;
int lst[ 100007 ] ;
bool f[ 100007 ] ;


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
    for ( i = 0 ; i <= 100000 ; i ++ )
        {
        lst[ i ] = -1 ;
        f[ i ] = true ;
        }
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        if ( lst[ a[ i ] ] != -1  )
            {
            if ( d[ a[ i ] ] != 0 && i - lst[ a[ i ] ] != d[ a[ i ] ] )
                {
                f[ a[ i ] ] = false ;
                }
            }
        if ( lst[ a[ i ] ] != -1 ) d[ a[ i ] ] = i - lst[ a[ i ] ] ;
        lst[ a[ i ] ] = i ;
        }
    }

void solve ( )
    {
    int i ;
    vector < int > ans ;
    vector < int > t ;
    ans.clear ( ) ;
    for ( i = 0 ; i <= 100000 ; i ++ )
        {
        if ( lst[ i ] != -1 && f[ i ] == true ) { ans.push_back ( i ) ; t.push_back ( d[ i ] ) ; }
        }
    printf ( "%d\n" , ans.size ( ) ) ;
    for ( i = 0 ; i < ans.size ( ) ; i ++ )
        {
        printf ( "%d %d\n" , ans[ i ] , t[ i ] ) ;
        }
    printf ( "\n" ) ;
    }