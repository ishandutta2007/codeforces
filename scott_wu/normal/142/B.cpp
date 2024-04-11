#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int nbits (int x)
{
    return (x == 0 ? 0 : 1 + nbits (x - (x & -x)));
}

int solve ()
{
    int mc[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int mr[8] = {1, -1, 1, -1, 2, -2, 2, -2};
    bool f[20][20];
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            f[i][j] = false;
    int pow = 1 << (n * m);
    int ans = 0;
    for (int t = 0; t < pow; t++)
    {
        if (nbits (t) <= ans) continue;
        bool check = true;
        for (int i = 2; i < 2 + n; i++)
            for (int j = 2; j < 2 + m; j++)
            {
                f[i][j] = t & (1 << ((i-2)*m+(j-2)));
                if (f[i][j])
                    for (int k = 0; k < 8; k++)
                        if (f[i-mc[k]][j-mr[k]])
                            check = false;
            }
        if (check) ans = max (ans, nbits (t));
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    if (n > m) swap (n, m);
    int ans = 0;
    if ((n * m) % 2 == 0)
    {
        if (n >= 3)
        {
            ans = n * m / 2;
        }
        else if (n == 1) ans = m;
        else if (n == 2)
            ans = m / 4 * 4 + 2 * min (m % 4, 2);
    }
    else
    {
        if (n == 1) ans = m;
        else if (n * m <= 20) ans = solve ();
        else ans = ((n * m + 1) / 2);
    }
    cout << ans << "\n";
    //system ("Pause");
    return 0;
}