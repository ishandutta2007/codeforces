#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int n ;
int k ;
int l , r ;
int s ;
int s1 ;


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
    scanf ( "%d" , &k ) ;
    scanf ( "%d%d" , &l , &r ) ;
    scanf ( "%d%d" , &s , &s1 ) ;
    }


void solve()
    {
    int s2 ;
    s2 = s - s1 ;
    int br = n - k ;
    int x , ost ;
    if ( br != 0 )
        {
        ost = s2 % br ;
        x = s2 / br ;
        }
    int i ;
    for ( i = 0 ; i < br ; i ++ )
        {
        if ( i + ost >= br )
            {
            printf ( "%d " , x + 1 ) ;
            }
        else printf ( "%d " , x ) ;
        }
    x = s1 / k ;
    ost = s1 % k ;
    for ( i = br ; i < n ; i ++ )
        {
        if ( ( i - br ) + ost >= k )
            {
            printf ( "%d " , x + 1 ) ;
            }
        else printf ( "%d " , x ) ;
        }
    printf ( "\n" ) ;
    }