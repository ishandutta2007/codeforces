#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;


int n , d , l , x , n1 ;

vector < int > ans;


int main()
    {
    cin >> n >> d >> l ;
    n1 = n ;
    while ( n > 1 )
        {
        if ( d < 1 )
            {
            x = 1 ;
            d = 1 - d ;
            if ( d < 1 )
                {
                x += ( 1 - d ) ;
                d = 1;
                }
            ans.push_back ( x ) ;
            }
        else
            {
            x = l;
            d = l - d ;
            if ( d > 1 )
                {
                x -= ( d - 1 ) ;
                d = 1;
                }
            ans.push_back ( x ) ;
            }
        n -- ;
        }
    ans.push_back ( d ) ;

    if ( d < 1 || d > l  )
        {
        cout << -1 << endl ;
        return 0 ;
        }
    int i ;
    for ( i = 0 ; i < n1 - 1 ; i ++ )
        {
        cout << ans[ i ] << " " ;
        }
    cout << ans[ n1 - 1 ] << endl ;
    return 0 ;
    }