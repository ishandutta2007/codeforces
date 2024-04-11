#include<iostream>
#include<stdio.h>
using namespace std;


int a , b ;

int f ( int x )
    {
    int k = b ;
    int p;
    while ( x != 0 )
        {
        p = x%10;
        x = x/ 10;
        if ( p != 4 && p != 7 ) continue;
        if ( p != k%10 ) return 0;
        k = k/10;
        }
    if ( k != 0 ) return 0;
    return 1;
    }

int main ( )
    {
    int i;
    scanf (  "%d%d" , &a, &b ) ;

    for ( i = a + 1; ;i ++ )
        {
        if ( f ( i ) == 1 ) break;
        }
    printf ( "%d\n", i );
    return 0;
    }