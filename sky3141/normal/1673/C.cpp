#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int MAXN = 40000 + 9, mod = 1000000007;

int n;
LL f[MAXN];
LL g[MAXN];

bool issym(int x)
{
    int t = x;
    int a = 0;
    while (t)
    {
        a = a * 10 + t % 10;
        t /= 10;
    }
    return a == x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    f[0] = 1;
    for (int i = 1; i <= 40000; ++i)
    {
        if (issym(i))
        {
            fill(g, g + MAXN, 0);
            for (int j = 0; j <= 40000; ++j)
            {
                g[j] = f[j];
                if (j >= i)
                    g[j] = (g[j] + g[j - i]) % mod;
            }
            for (int j = 40000; j >= i; --j)
            {
                f[j] = (f[j] + g[j - i]) % mod;
            }
        }
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        cout << f[x] << '\n';
    }

    return 0;
}