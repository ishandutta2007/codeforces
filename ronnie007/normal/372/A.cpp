#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

int n ;
int a[ 5000007 ] ;
int br[ 5000007 ] ;

void input ( ) ;
void solve ( ) ;


int main()
    {
    input ( ) ;
    solve ( ) ;
    return 0;
    }


void input()
    {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        }
    sort ( a , a + n ) ;
    }

void solve()
    {
    int ans = n ;
    int i ;
    int ind = n / 2 ;

    for ( i = 0 ; i < n / 2 ; i ++ )
        {
        for ( ;; )
            {
            if ( a[ i ] * 2 <= a[ ind ] )
                {
                ind ++ ;
                ans -- ;
                break ;
                }
            else ind ++ ;
            if ( ind == n ) break ;
            }
        if ( ind == n ) break ;
        }
    printf ( "%d\n" , ans ) ;
    }