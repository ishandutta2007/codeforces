#include<iostream>
#include<stdio.h>
using namespace std;

int n,m,x[1024],y;

int main ()
    {
    int i , a , b;
    scanf( "%d%d" , &n, &m);
    for ( i = 0 ; i < m ; i ++ )
        {
        scanf( "%d%d" , &a , &b ) ;
        x[ a ] = 1;
        x[ b ] = 1;
        }
    for ( i = 1 ; i <= n ; i ++ )if ( x[i]==0 ){ y = i ; break ; }

    printf("%d\n",n-1);
    for ( i = 1 ; i <= n ;i ++ )
        {
        if ( i == y )continue;
        printf( "%d %d\n" , y , i );
        }
    return 0;
    }