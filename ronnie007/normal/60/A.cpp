#include<iostream>
#include<stdio.h>
#include<string>
using namespace std ;

int l , r ;
int n , m ;

string a ;


int main ( )
    {
    int i ;
    cin >> n >> m ;
    l = 1 ;
    r = n  ;
    int x ;
    bool fl = true ;  ;
    for ( i = 0 ; i < m ; i ++ )
        {
        fl = true ;
        cin >> a ;
        cin >> a ;
        cin >> a ;
        if ( a[ 0 ] == 'r' ) fl = true ;
        else fl = false ;
        cin >> a ;
        cin >> x ;
        if ( fl == true ) x ++ ;
        else x -- ;
        if ( fl == true && l < x ) l = x ;
        if ( fl == false && r > x ) r = x ;
        }
    if ( r >= l ) printf ( "%d\n" , r - l + 1 ) ;
    else printf ( "-1\n" ) ;
    return 0 ;
    }