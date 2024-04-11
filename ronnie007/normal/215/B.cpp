#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 5010;
double datx[maxn], daty[maxn], datz[maxn], p, a, b;
int n, m, k;
double ans;
inline double sqr(double x)
    {
    return x * x;
    }
int main()
    {
    scanf ( "%d" , &n ) ;
    for (int i = 0 ; i < n ; i ++ ) scanf ( "%lf" , datx + i ) ;
    scanf ( "%d" , &m ) ;
    for ( int i = 0 ; i < m ; i ++ ) scanf ( "%lf", daty + i ) ;
    scanf ( "%d" , &k ) ;
    for (int i = 0 ; i < k ; i ++ ) scanf ( "%lf" , datz + i ) ;
    scanf ( "%lf%lf" , &a , &b ) ;
    sort ( datx , datx + n ) ;
    double temp ;
    for (int i = 0 ; i < m ; i ++ )
        {
        for ( int j = 0 ; j < k ; j ++ )
            {
            temp = sqr ( datx[ n - 1 ] ) * b / a * daty[ i ] / ( daty[ i ] * b / a + datz[ j ] );
            ans = max (ans , temp ) ;
            }
        }
    printf ( "%.8lf\n" , sqrt( ans ) ) ;
    return 0;
    }