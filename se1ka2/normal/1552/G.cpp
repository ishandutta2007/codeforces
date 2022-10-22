#include <iostream>
using namespace std;
typedef long long ll;

int m[12];
int l[12];
int f[12][42];
ll x[12];
ll y[12];

bool rec(int i, int k, int n, ll u)
{
    if (i == k)
    {
        for (int j = 0; j <= n; j++)
        {
            if (u == (1ll << j) - 1)
            {
                return true;
            }
        }
        return false;
    }
    ll v = u & x[i];
    int c = 0;
    while(v)
    {
        c += (v & 1);
        v >>= 1;
    }
    u &= y[i];
    for (int j = 0; j < c; j++)
    {
        u ^= (1ll << f[i][j]);
    }
    bool res = rec(i + 1, k, n, u);
    for (int j = c; j < c + l[i]; j++)
    {
        u ^= (1ll << f[i][j]);
        res &= rec(i + 1, k, n, u);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> m[i];
        for (int j = 0; j < m[i]; j++)
        {
            cin >> f[i][j];
            f[i][j]--;
            x[i] ^= (1ll << f[i][j]);
        }
        y[i] = (1ll << n) - 1 - x[i];
    }
    bool b[42]{0};
    int c = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < m[i]; j++)
        {
            l[i] += !b[f[i][j]];
            b[f[i][j]] = true;
        }
        c += l[i];
    }
    if (c >= n - 1 && rec(0, k, n, 0))
    {
        cout << "ACCEPTED\n";
    }
    else
    {
        cout << "REJECTED\n";
    }
}