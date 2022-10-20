#include<iostream>
#include<stdio.h>
using namespace std;

int main( )
    {
    int a[ 7 ];
    int ans = 0;
    int ans1 = 0;
    int ans2 = 0;
    scanf ( "%d%d%d",&a[ 0 ],&a[ 1 ],&a[ 2 ] );
    ans = a[ 0 ]/3 + a[ 1 ]/3 + a[ 2 ]/3;
    if ( a[ 0 ] > 0 && a[ 1 ] > 0 && a[ 2 ] > 0 )ans1 = ( a[ 0 ] - 1 )/3 + (a[ 1 ] - 1 )/3 + (a[ 2 ] - 1 )/3 + 1;
    if ( a[ 0 ] > 1 && a[ 1 ] > 1 && a[ 2 ] > 1 )ans2 = ( a[ 0 ] - 2 )/3 + (a[ 1 ] - 2 )/3 + (a[ 2 ] - 2 )/3 + 2;

    if ( ans < ans1 ) ans = ans1;
    if ( ans < ans2 ) ans = ans2;

    printf("%d\n",ans);
    return 0;
    }