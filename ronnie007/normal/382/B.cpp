#include<iostream>
#include<stdio.h>
using namespace std ;


#define ll long long

int main ( ) {
    int a , b , w , x , c ;
    cin >> a >> b >> w >> x >> c ;
    ll l = -1 , r = 1e13 ;
    ll mid ;
    ll g , e , y ;
    while ( r - l > 1) {
        mid = ( l + r ) / 2 ;
        g = b - mid*x;
        e = a + ( g - w + 1 ) / w ;
        y = c - mid;
        if ( y <= e ) r = mid ;
        else l = mid ;
        }
    cout << r << endl;
    return 0 ;
    }