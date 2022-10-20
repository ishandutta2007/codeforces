#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;



int main( )
    {
    string a ;
    string ans ;
    cin >> a ;
    int n = a.size();
    int i ;
    int p ;
    int ch ;
    ans.clear() ;
    p = 0;
    for( i = 0 ; i < n; )
        {
        ch = 0;
        if ( i != 0 )
            {
            if ( i + 3 < n )
                {
                if ( a[i] == 'd' && a[i+1] == 'o' && a[i+2] == 't' )
                    {
                    i = i + 3;
                    ans = ans + '.' ;
                    ch = 1;
                    }
                }
            if ( i + 2 < n )
                {
                if ( a[i] =='a' && a[i+1] == 't'  && p == 0)
                    {
                    i = i + 2;
                    ans = ans + '@';
                    ch = 1;
                    p = 1;
                    }
                }
            }
        if ( ch == 0 )
            {
            ans = ans + a[i];
            i ++;

            }
        }
    cout << ans << " \n " ;
    return 0;
    }