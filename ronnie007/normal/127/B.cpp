#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;


int main()
    {
    int n;
    int a[ 107 ];
    int i,j;
    scanf ( "%d" , &n );

    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &a[i] );
        }
    sort ( a , a + n );
    i = 0;
    int ans = 0;
    while( i < n )
        {
        if ( a[ i ] == a[ i + 1 ] )
            {
            ans ++;
            i = i + 2;
            }
        else i ++;
        }
    printf ( "%d\n" , ans/2);
    return 0;
    }