#include<iostream>
#include<stdio.h>
using namespace std;


int main()
    {
    int n;
    scanf( "%d" , &n ) ;
    int ans = 0;
    ans = (n/2) * (n/2 + n%2);
    printf("%d\n" , ans);
    int i , j ;
    for(i = 1 ; i <= n/2 ; i++)
        {
        for ( j = n/2 +1 ; j <= n ; j++ )
            {
            printf("%d %d\n",i,j);
            }
        }
    return 0;
    }