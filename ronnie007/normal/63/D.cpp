#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstdlib>
#include <math.h>

typedef long long ll;
#define MAX_L 100000

using namespace std;

ll nextInt()
    {
    char c;
    bool signum = false;
    while ( c = getchar ( ) , c < '0' || c > '9' ) if ( c == '-' ) break;

    if ( c == '-' )
        {
        signum = true ;
        c = getchar ( ) ;
        }
    ll answer = c - '0' ;
    while ( c = getchar ( ) , c >= '0' && c <= '9' )
        {
        answer *= 10 ;
        answer += c - '0' ;
        }
    if ( signum ) answer = -answer;
    return answer;
    }



int main()
    {
    //("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int a , b , c , d , n ;
    cin >> a >> b >> c >> d >> n;
    int x[ 100 ];
    for ( int i = 0 ; i < n ; i ++ ) cin >> x[ i ];

    int matrix[ 200 ][ 200 ];

    for ( int i = 0 ; i < 200 ; i ++ )
        for ( int j = 0 ; j < 200 ; j ++ )
            matrix[ i ][ j ] = -1 ;

    bool up ;
    int colnum = 0 ;
    up = (a&1) == 0 ;
    colnum = 0 ;
    int party = 0 ;
    for (colnum = 0 ; colnum < a + c ; colnum ++ )
    {
        int len = ( colnum < a ) ? b : d;
        int st = up ? 0 : len - 1 ;
        int fin = up ? len : -1 ;
        for (int i = st ; i != fin ; i += up?1:-1)
        {
            if ( x[ party ] == 0 ) party++;
            matrix[ colnum ][ i ] = party;
            x[ party ] -- ;
        }
        up = !up;
    }

    cout << "YES" << endl;

    for (int i = 0 ;i < max( b , d ) ; i ++ )
        {
        for (int j = 0 ; j < a + c ; j ++ )
            {
            if (matrix[ j ][ i ]==-1) cout << '.';
            else cout << (char)(matrix[ j ][ i ]+'a');
            }
        cout << endl;
        }

    }