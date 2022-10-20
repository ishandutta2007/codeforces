#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int n , m , q ;

int dp[ 43 ][ 43 ][ 43 ][ 43 ] ;
char cc[ 43 ][ 43 ] ;
int s[ 43 ][ 43 ] ;
int aa[ 43 ][ 43 ] ;

void input ( ) ;
void solve ( ) ;


int main()
    {
    input ( ) ;
    solve ( ) ;
    return 0;
    }




void input()
    {
    cin >> n >> m >> q ;
    int i , j ;
    string k ;
    for ( i = 1 ; i <= n ; i ++ )
        {
        cin >> k ;
        for ( j = 1 ; j <= m ; j ++ )
            {
            aa[ i ][ j ] =  ( k[ j - 1 ] == '1' ) ;
            }
        }

    }


void solve()
    {
    int li , lj ;
    int i , j ;
    int x , y ;
    int a , b , c , d ;
    s[ 0 ][ 0 ] = 0 ;
    ///cout << "here\n" ;
    for ( i = 1 ; i <= n ; i ++ )
        {
        for ( j = 1 ; j <= m ; j ++ )
            {
            s[ i ][ j ] = s[ i - 1 ][ j ] + s[ i ][ j - 1 ] - s[ i - 1 ][ j - 1 ] + aa[ i ][ j ] ;
            }
        }
    int l1 , l2 ;

    int ans = 0 ;
    for ( li = 0 ; li < n ; li ++ )
        {
        for ( lj = 0 ; lj < m ; lj ++ )
            {
            for ( a = 1 ; a + li <= n ; a ++ )
                {
                for ( c = 1 ; c + lj <= m ; c ++ )
                    {
                    b = a + li ;
                    d = c + lj ;
                    ans = 0 ;

                    for ( x = a ; x <= b ; x ++ )
                        {
                        for ( y = c ; y <= d ; y ++ )
                            {
                            if ( ( s[ x ][ y ] - s[ a - 1 ][ y ] - s[ x ][ c - 1 ] + s[ a - 1 ][ c - 1 ] ) == 0 ) ans ++ ;
                            }
                        }
                    ///ans += dp[ a + 1 ][ b ][ c ][ d ] ;
                    ///ans += dp[ a ][ b ][ c + 1 ][ d ] ;
                    ///ans -= dp[ a + 1 ][ b ][ c + 1 ][ d ] ;
                    ans += dp[ a + 1 ][ b ][ c ][ d ] + dp[ a ][ b ][ c + 1 ][ d ] - dp[ a + 1 ][ b ][ c + 1 ][ d ] ;
                    dp[ a ][ b ][ c ][ d ] = ans ;
                    ///cout << dp[ 4 ][ 5 ][ 4 ][ 5 ] << "\n" ;
                    }
                }
            }
        }
    ///cout << "here\n" ;
    for ( i = 0 ; i < q ; i ++ )
        {
        cin >> a >> c >> b >> d ;
        ///cout << "here" ;
        cout << dp[ a ][ b ][ c ][ d ] << "\n" ;
        }
    }