#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
    ll x, y, m;
    cin >> x >> y >> m;
    
    if (x > y) swap (x, y);
    
    if (y <= 0)
    {
        if (y < m)
            cout << "-1\n";
        else
            cout << "0\n";
        return 0;
    }
    
    if (y >= m)
    {
        cout << "0\n";
        return 0;
    }
    
    ll res = 0;
    if (x < 0)
    {
        res = (-x - 1) / y + 1;
        
        x += res * y;
    }
    
    while (y < m)
    {
        x = x + y;
        swap (x, y);
        res++;
    }
    
    cout << res << "\n";
    //system ("Pause");
    return 0;
}