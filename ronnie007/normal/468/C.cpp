#include<bits/stdc++.h>
using namespace std ;

long long n ;

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    long long sm = 0 ;
    long long en = 1 ;
    int len = 17 ;
    for ( int i = 0 ; i < len ; ++ i ) {
        en *= 10 ;
    }
    sm = ( ( ( ( ( en / 10 ) % n ) * len ) % n ) * 45 + 1 ) % n ;
    long long diff = n - sm ;
    cout << diff + 1 << " " << en + diff << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}