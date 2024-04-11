#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
using namespace std;


double n , m ;

void input ( ) ;
void solve ( ) ;


double fastpow ( double a , int x ) {
    double r = 1 ;
    while ( x != 0 ) {
        if ( x % 2 == 0 ) {
            x /= 2 ;
            a = a * a ;
        }
        else {
            x -- ;
            r = r * a ;
        }
    }
    return r ;
}


int main ( ) {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    scanf ( "%lf%lf" , &n , &m ) ;
}

void solve ( ) {
    int i ;
    double ans = 0 ;
    double cur ;
    for ( i = 1 ; i <= n ; i ++ ) {
        ///printf ( "%.7lf %.7lf\n" , ans , cur ) ;
        ans += i * ( fastpow ( ( i / n ) , m ) - fastpow ( ( i - 1 ) / n , m ) ) ;
    }
    printf ( "%.7lf\n" , ans ) ;
}