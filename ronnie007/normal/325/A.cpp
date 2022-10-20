#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;


int n;
int x , y , x1 , y1;
vector < pair < int , int > > v ;



void input (  ) ;
void solve (  ) ;

int main ( )
    {
    input ( ) ;
    solve ( ) ;
    return 0;
    }



void input (  )
    {
    scanf ( "%d" , &n) ;
    int i ;
    int ans = 0;
    int tp = 0 ;
    int bt = 10000000 ;
    int iz = 0 , zp =  100000000 ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d%d%d%d" , &x , &y , &x1 , &y1 ) ;
        ans = ans + ( x1 - x ) * ( y1 - y ) ;
        if ( tp < x1 ) tp = x1 ;
        if ( bt > x ) bt = x ;
        if ( iz < y1 ) iz = y1 ;
        if ( zp > y  ) zp = y ;
        }
    if ( ( iz - zp ) * ( tp - bt ) == ans  && iz - zp == tp - bt ) printf("YES\n");
    else printf ("NO\n");
    }
void solve (  )
    {
    }