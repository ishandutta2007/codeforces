#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll b[2][105];

int main()
{
    int t;
    cin >> t;
    ll f[75];
    f[0] = f[1] = 1;
    for (int i = 2; i < 60; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    while (t--)
    {
        int n;
        cin >> n;
        ll c[105];
        ll s = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
            s += c[i];
        }
        ll y = 0;
        ll u = 0;
        for (int i = 0; i < 60; i++)
        {
            u += f[i];
            y ^= (1ll << i);
            if (u >= s)
            {
                if (u > s)
                {
                    y = -1;
                }
                break;
            }
        }
        if (y == -1)
        {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            b[0][i] = b[1][i] = 0;
            ll d = c[i];
            for (int j = 59; j >= 0; j--)
            {
                if (d >= f[j])
                {
                    b[0][i] ^= (1ll << j);
                    d -= f[j];
                    j--;
                }
            }
            d = c[i];
            for (int j = 59; j >= 0; j--)
            {
                if (d > f[j] || (d == f[j] && j % 2 == 0))
                {
                    b[1][i] ^= (1ll << j);
                    d -= f[j];
                    j--;
                }
            }
        }
        bool f = false;
        for (int k = 0; k <= n; k++)
        {
            ll s = 0;
            f = true;
            for (int i = 0; i < n; i++)
            {
                ll r = b[0][i];
                if (i == k)
                {
                    r = b[1][i];
                }
                if (s + r != (s | r))
                {
                    f = false;
                    break;
                }
                s += r;
            }
            if (s != y)
            {
                f = false;
            }
            if (f)
            {
                break;
            }
        }
        if (f)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}