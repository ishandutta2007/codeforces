#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<map>
using namespace std;


#define MIN (a,b) (((a)<(b))?(a):(b))

int n ;
string a ;
int x[ 100007 ] ;
int y[ 100007 ] ;
int z[ 100007 ] ;


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
    cin >> a ;
    n = a.size ( ) ;
    }

void solve ( )
    {
    int i ;
    for ( i = 1 ; i <= n ; i ++ )
        {
        if ( a[ i - 1 ] == 'x' )
            {
            x[ i ] = x[ i - 1 ] + 1 ;
            }
        else x[ i ] = x[ i - 1 ] ;

        if ( a[ i - 1 ] == 'y' )
            {
            y[ i ] = y[ i - 1 ] + 1 ;
            }
        else y[ i ] = y[ i - 1 ] ;

        if ( a[ i - 1 ] == 'z' )
            {
            z[ i ] = z[ i - 1 ] + 1 ;
            }
        else z[ i ] = z[ i - 1 ] ;
        }
    int m ;
    int l , r ;
    int br = 0 ;
    int br1 = 0 ;
    int br2 = 0 ;
    int k ;
    scanf ( "%d" , &m ) ;
    for ( i = 0 ; i < m ; i ++ )
        {
        scanf ( "%d%d" , &l , &r ) ;
        br = x[ r ] - x[ l - 1 ] ;
        br1 = y[ r ] - y[ l - 1 ] ;
        br2 = z[ r ] - z[ l - 1 ] ;
        if ( br <= br1 && br <= br2 ) k = br ;
        if ( br1 <= br && br1 <= br2 ) k = br1 ;
        if ( br2 <= br && br2 <= br1 ) k = br2 ;
        br -= k ;
        br1 -= k ;
        br2 -= k ;
        if ( ( br <=1 && br1 <= 1 && br2 <= 1 ) || ( r - l + 1 < 3 ) )
            {
            printf ( "YES\n" ) ;
            }
        else printf ( "NO\n" ) ;
        }
    }