#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std ;

int m;
int n ;
char s[ 20007 ] ;

int main()
    {
    scanf("%d", &n);
    scanf("%s", s);
    m = strlen( s );

    int ans = 0;
    int i ;
    for ( i = 0; i < m; i += n)
        {
        if ( i == 0 )continue;
        if ( s [ i - 1 ] == s [ i - 2 ]  && s [ i - 2 ]  == s [ i - 3 ] )ans++ ;
        }
    printf( "%d\n" , ans );
    return 0;
    }