#include <iostream>
using namespace std;

int n , x , y , c ;
long long calc ( long long t )
    {
    long long int ret = 0 ;
    ret += 2 * t * ( t + 1 ) - 4 * t + 1 ;
    if ( t > x )
        {
        ret -= ( t - x ) * ( t - x) ;
        }
    if ( t > n - x + 1 )
        {
        ret -= ( t - n + x - 1 ) * ( t - n + x - 1 ) ;
        }
    if ( t > y )
        {
        ret -= ( t - y ) * ( t - y ) ;
        }
    if ( t > n - y + 1 )
        {
        ret -= ( t - n +  y - 1 ) * ( t - n + y - 1 ) ;
        }
    if ( t > x + y )
        {
        ret += ( ( t - x - y ) * ( t - x - y + 1 ) / 2 ) ;
        }
    if ( t > x + n - y + 1 )
        {
        ret += ( ( t - x - n + y - 1 ) * ( t - x - n + y - 1 + 1 ) / 2 ) ;
        }
    if ( t > n - x + 1 + y )
        {
        ret += ( ( t - n + x - 1 - y ) * ( t - n + x - 1 - y + 1 ) / 2 ) ;
        }
    if ( t > n - x + 1 + n - y + 1 )
        {
        ret += ( ( t - n + x - 1 - n + y - 1 ) * ( t - n + x - 1 - n + y - 1 + 1 ) / 2 ) ;
        }
    return ret;
    }
int main()
    {
    cin >> n >> x >> y >> c ;
    int l = 0 , r = 1000000002 ;
    while ( r - l > 1 )
        {
        if ( calc( ( r + l ) / 2 ) < c )
            {
            l = ( r + l ) / 2 ;
            }
        else
            {
            r= ( r + l ) / 2 ;
            }
        }
    cout << r - 1 << endl ;
    }