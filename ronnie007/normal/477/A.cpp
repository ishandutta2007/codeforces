#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

#define MOD 1000000007

long long a , b ;
long long ans = 0 ; 

void input ( ) ;
void solve ( ) ;


int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ; 
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( )  {
    cin >> a >> b ; 
}

void solve ( )  {
    long long k ;
    long long x ;
    long long sm = ( b * ( b - 1 ) ) / 2 ;
    sm %= MOD ;
    ans = 0 ;
    for ( k = 1 ; k <= a ; k ++ ) {
        x = k * b ;
        x = x + 1 ;
        x %= MOD ;
        ans += x * sm ;
        ans %= MOD ;
    }
    cout << ans << "\n" ; 
}