#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

char a[ 100007 ];

int main()
    {
    int i;
    int n,k;
    int x;
    scanf( "%d%d" , &n,&k);
    scanf("%s",&a);

    for ( i = 0 ; i < n ; i ++ )
        {
        if ( i + 2 < n &&  a[ i ] == '4' && a[ i + 2 ] == '7' && ( a[ i + 1 ]=='4' || a[ i + 1 ]=='7')  && i%2 == 0)
            {
            ///printf ( " %d\n " , i );
            if ( k%2 == 0 )break;
            x = a[ i + 1 ] - '0';
            x = 11 - x;
            a[ i + 1 ] = x + '0';
            break;
            }
        if ( a[ i ] == '4' && a[ i + 1 ] == '7'  && k > 0)
            {
            if ( i%2 == 0 ) a[ i + 1 ] = '4';
            else a [ i ] = '7';
            k--;
            }
        }
    printf("%s\n",a);
    return 0;
    }