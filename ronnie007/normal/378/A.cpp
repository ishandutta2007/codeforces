#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

int a , b ;

void input ( ) ;
void solve ( ) ;


int main()
    {
    input ( ) ;
    solve ( ) ;
    return 0;
    }


void input ( )
    {
    scanf ( "%d%d" , &a , &b ) ;
    }

void solve ( )
    {
    int br1 = 0 ;
    int br2 = 0 ;
    int br3 = 0 ;
    int i ;
    int x , y ;
    for ( i = 1 ; i <= 6 ; i ++ )
        {
        x = abs ( i - a ) ;
        y = abs ( i - b ) ;
        if ( x < y ) br1 ++ ;
        if ( x == y ) br2 ++ ;
        if ( y < x ) br3 ++ ;
        }
    printf ( "%d %d %d\n" , br1 , br2 , br3 ) ;
    }