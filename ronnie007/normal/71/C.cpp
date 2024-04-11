#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
using namespace std ;


int n ;
int a[ 100007 ] ;
int br[ 100007 ] ;

vector < int > v ;

set < int > s ;

void getdivisors ( )
    {
    int x = n ;
    int i = 2 ;
    while ( x != 1 )
        {
        if ( x % i == 0 )
            {
            v.push_back ( i ) ;
            x /= i ;
            }
        else i ++ ;
        }
    s.insert ( 1 ) ;
    set < int > ::iterator j ;
    set < int > b ;
    for ( i = 0 ; i < v.size ( ) ; i ++ )
        {
        b.clear ( ) ;
        for ( j = s.begin ( ) ; j != s.end ( ) ; j ++ )
            {
            b.insert ( ( *j ) * v[ i ] ) ;
            }
        for ( j = b.begin ( ) ; j != b.end ( ) ; j ++ )
            {
            s.insert ( *j ) ;
            }
        }
    }

void solve ( )
    {
    set < int > ::iterator j ;
    int i ;
    for ( j = s.begin ( ) ; j != s.end ( ) ; j ++ )
        {
        if ( 3 * (*j) > n ) continue ;
        for ( i = 0 ; i < n ; i ++ )
            {
            br[ i ] = 0 ;
            }
        for ( i = 0 ; i < n ; i ++ )
            {
            if ( a[ i ] == 1 ) br[ i % ( *j ) ] ++ ;
            if ( br[ i % ( *j ) ] == ( n / ( *j ) ) )
                {
                printf ( "YES\n" ) ;
                return ;
                }
            }
        }
    printf ( "NO\n" ) ;
    }

int main ( )
    {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        }
    getdivisors ( ) ;
    solve ( ) ;
    return 0 ;
    }