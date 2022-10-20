#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;




void input();
void solve();



int main()
    {
    input();
    solve() ;
    return 0;
    }


void input()
    {

    }



void solve ( )
    {
    int n, x;
    cin >> n >> x ;
    vector < int > MAS1, MAS2;
    MAS1.resize ( n ) ;
    MAS2.resize ( n ) ;
    int i , j , ans ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &MAS1[ i ] ) ;
        }
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &MAS2[ i ] ) ;
        }
    sort ( MAS1.begin ( ) , MAS1.end ( ) ) ;
    sort ( MAS2.begin ( ) , MAS2.end ( ) ) ;
    reverse ( MAS1.begin ( ) , MAS1.end ( ) ) ;


    i = 0 ;
    j = 0 ;
    ans = 0 ;
    int k ;
    for( k = 0; k < n ; k ++ )
        {
        if ( MAS1[ i ] + MAS2[ j ] >= x )
            {
            ans ++ ;
            i++ ;
            j++ ;
            }
        else
            {
            j++ ;
            }
        }

    cout << 1 << " " << ans << "\n" ;


    }