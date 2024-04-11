#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, d, h, i;
    cin >> n >> d >> h;

    if(d > 2 * h or (d == h and h == 1 and n > 2))
    {
        cout << -1;
        return 0;
    }

    if(d == h)
    {
        for(i = 1; i <= h; i++)
        {
            cout << i << " " << i + 1 << endl;
        }
        for(i = h + 2; i <= n; i++)
        {
            cout << 2 << " " << i << endl;
        }
        return 0;
    }

    for(i = 1; i <= h; i++)
    {
        cout << i << " " << i + 1 << endl;
    }
    if(d > h)
    {
        cout << 1 << " " << h + 2 << endl;
    }
    for(i = h + 2; i <= d; i++)
    {
        cout << i << " " << i + 1 << endl;
    }
    for(i = d + 2; i <= n; i++)
    {
        cout << 1 << " " << i << endl;
    }
    return 0;


}