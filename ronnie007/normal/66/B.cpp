#include<iostream>
#include<stdio.h>
using namespace std;

int n;

int a[ 1007 ] ;


int num ( int x )
    {
    int l , r ;
    int ans = 1 ;
    for ( l = x-1 ; l >= 0 ; l-- )
        {
        if ( a[ l ] <= a[ l + 1 ] ) ans++;
        else break;
        }
    for ( r = x+1 ; r < n ; r++ )
        {
        if ( a[ r - 1 ] >= a[ r ] ) ans++;
        else break;
        }
    return ans;
    }

int main ()
    {
    int i;
    int ans=0;
    int mx=0;
    scanf( "%d", &n);
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf( "%d",&a[i]);
        }
    for ( i = 0 ; i < n ; i ++ )
        {
        ans = num( i );
        if ( ans > mx) mx = ans;
        }
    printf ( "%d\n" , mx);
    return 0;
    }