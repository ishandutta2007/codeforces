#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;


string a,b,c;

string p;

int n;

string convert ( string x );
int check( string x);

int main()
    {
    cin >> a;
    cin >> b;
    cin >> c;
    a=convert(a);
    b=convert(b);
    c=convert(c);
    int i;
    cin >> n;
    for ( i = 0 ; i < n ; i ++)
        {
        cin >> p;
        p=convert( p );
        if( check( p ) == 1 ) printf ( "ACC\n" );
        else printf ( "WA\n" ) ;
        }
    return 0;
    }


string convert ( string x )
    {
    string ans ;
    int i;
    ans.clear();
    for ( i = 0 ; i < x.size() ; i ++ )
        {
        if( x[ i ] !=';' && x[ i ] != '-' && x[ i ] !='_' )
            {
            if( x[ i ] >= 'A' && x[ i ] <= 'Z' )
                {
                x[ i ]=((x[ i ] - 'A') + 'a');
                }
            ans = ans + x[ i ];
            }
        }
    return ans;
    }

int check( string x)
    {
    if ( x == a + b + c || x == a + c + b || x == b + a + c || x == b + c + a || x == c + a + b || x == c + b + a ) return 1;
    return 0;
    }