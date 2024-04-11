#include<iostream>
#include<stdio.h>
using namespace std;

int n , k ;

int f ( int x )
    {
    int g = n ;
    while ( x != 0 )
        {
        g = g - x;
        if ( g <= 0 ) return 1;
        x = x / k;
        }
    return 0;
    }
int main ( )
    {

    int v ;
    int l , r;
    int md;

    scanf ( "%d%d" , &n, &k );
    l = 1 ;
    r = n ;
    while ( r - l > 1 )
        {
        ///printf ( "%d %d\n", l , r );
        md = ( r + l ) / 2;
        if ( f ( md ) == 1 ) r = md ;
        else l = md;
        }
    if ( f ( l ) == 0 ) l ++;
    printf ( "%d\n" , l );
    return 0 ;
    }