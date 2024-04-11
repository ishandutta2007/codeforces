#include<bits/stdc++.h>
using namespace std ;

long double a , b , bad , dc ;
long double ans = 0.0 ;

void rec ( long double x , long double y , long double z , long double coef , int len ) {
    ans += coef ;
    if ( len > 23 ) { return ; }
    if ( x < 0 && y < 0 ) { return ; }
    if ( x < 0 ) {
        if ( y > dc + 1e-10 ) {
            rec ( x , y - dc , z + dc , coef * y , len + 1 ) ;
        }
        else {
            rec ( x , -1 , 1.0 , coef * y , len + 1 ) ;
        }
    }
    else if ( y < 0 ) {
        if ( x > dc + 1e-10 ) {
            rec ( x - dc , y , z + dc , coef * x , len + 1 ) ;
        }        
        else {
            rec ( -1 , y , 1.0 , coef * x , len + 1 ) ;
        }
    }
    else {
        if ( x > dc + 1e-10 ) {
            rec ( x - dc , y + dc / 2 , z + dc / 2 , coef * x , len + 1 ) ;
        }
        else {
            rec ( -1 , y + x / 2 , z + x / 2 , coef * x , len + 1 ) ;
        }
        if ( y > dc + 1e-10 ) {
            rec ( x + dc / 2 , y - dc , z + dc / 2 , coef * y , len + 1 ) ;
        }
        else {
            rec ( x + y / 2 , -1 , z + y / 2 , coef * y , len + 1 ) ;
        }
    }
}
          
void input ( ) {
    cin >> a >> b >> bad >> dc ;
}

void solve ( ) {
    ans = 0.0 ;
    rec ( a , b , bad , 1.0 , 1 ) ;
    cout << fixed << setprecision ( 12 ) << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // t = 1 ;
    // cin >> t ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}