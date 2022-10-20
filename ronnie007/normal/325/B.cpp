#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n;
vector<long long> sol;

int main()
{
    long long l, r, m, a;
    int s;
    
    cin >> n;
    
    for ( s = 0; s <= 62; s++ )
    {
        a = (1LL<<s) - 1;
        l = 0; r = 2000000000;
        if ( a > 0 )
        {
            r = 1;
            while ( ( r*a <= n ) && ( r <= 2000000000 ) )
            {
                r *= 2;
            }
            if ( r > 2000000000 )
                r = 2000000000;
        }
        while ( l+1 < r )
        {
            m = (l+r)/2;
            if ( m*(m-1)/2 + a*m < n )
                l = m;
            else
                r = m;
        }
        if ( r*(r-1)/2 + a*r == n && (r%2 == 1) )
        {
            for (int i = 0; i < s; i++)
            {
                r *= 2LL;
            }
            
            sol.push_back( r );
        }
    }
    sort( sol.begin(), sol.end() );
    for (int i = 0; i < (int) sol.size(); i++)
    {
        if ( i == 0 || sol[i] > sol[i-1] )
            cout << sol[i] << "\n";
    }
    if ( (int) sol.size() == 0 )
        cout << "-1\n";
    return 0;
}