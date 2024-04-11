#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
using namespace std ;

int k ;
int d ;

void input ( ) ;
void solve ( ) ;

int main ( )
    {
    input ( ) ;
    solve ( ) ;
    return 0 ;
    }


void input ( )
    {
    scanf ( "%d%d" , &k , &d ) ;
    }


void solve ( )
    {

    int i ;
    if ( d == 0 && k != 1 ) printf ( "No solution\n" ) ;
    else
        {
        printf ( "%d" , d ) ;
        for ( i = 1 ; i < k ; i ++ ) printf ( "0" ) ;
        }
    printf ( "\n"  );
    }