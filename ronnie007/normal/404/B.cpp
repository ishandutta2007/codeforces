#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
using namespace std ;

double a , d ;
int n ; 

void input ( ) ;
void solve ( ) ;

int main ( )  {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( )  {
    cin >> a >> d ;
    cin >> n ;
}

void solve ( )  {
    int i ;
    double x , y ;
    double dist = 0 ;
    double dist1 = 0 ;
    double l = 4 * a ; 
    x = 0 ;
    y = 0 ;
    int p ; 
    for ( i = 1 ; i <= n ; i ++ ) {
        dist1 += d ;
        p = int( dist1 / l ) ;
        dist1 -= p * l ;
        dist = dist1 ;
        x = 0 ;
        y = 0 ; 
        if ( dist >= a ) {
            x += a ;
            dist -= a ;
        }
        else {
            x += dist ;
            dist = 0 ;
        }

        if ( dist >= a ) {
            y += a ;
            dist -= a ;
        }
        else {
            y += dist ;
            dist = 0 ;
        }   


        if ( dist >= a ) {
            x -= a ;
            dist -= a ;
        }
        else {
            x -= dist ;
            dist = 0 ;
        }


        if ( dist >= a ) {
            y -= a ;
            dist -= a ;
        }
        else {
            y -= dist ;
            dist = 0 ;
        }
        cout << x << " " << y << "\n" ;
    }
}