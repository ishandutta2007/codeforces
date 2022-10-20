#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;

int main ( )
    {
    int k ;
    vector < long long > v ;
    v.clear( );
    string a;
    cin >> k;
    cin >> a;
    int i ;
    int n = a .size ( ) ;
    int br = 0 ;
    if ( k == 0 )
        {
        long long ans = 0;
        br = 0;
        for ( i = 0 ; i < n ; i ++ )
            {
            if ( a[ i ] == '0' ) { br ++ ; ans = ans + br ; }
            else br = 0;
            }
        printf("%I64d\n",ans);
        return 0;
        }
    for ( i = 0 ; i < n ; i ++ )
        {
        if ( a[ i ] == '1' ) {v.push_back ( br );br = 0 ; }
        else br ++ ;
        }
    v.push_back ( br );
    k -- ;
    long long ans = 0;
    for ( i = 0 ; i + k + 1< v.size( ) ; i ++ )
        {
        ans = ans + ( v[ i ] + 1 ) * ( v[ i + k + 1] + 1 ) ;
        ///cout << ans << "\n";
        }
    printf ( "%I64d\n" , ans );
    return 0;
    }