#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    ll g = gcd(a, b);
    return a / g * b;
}

int main()
{
    int n;
    cin >> n;
    int d[100005]{0};
    ll ans = 0;
    for (int c = 1; c <= n - 2; c++)
    {
        int e = (n - c);
        vector<int> w;
        for (int i = 1; i * i <= e; i++)
        {
            if (e % i == 0)
            {
                w.push_back(i);
                if (i * i < e)
                {
                    w.push_back(e / i);
                }
            }
        }
        sort(w.begin(), w.end(), greater<int>());
        for (int i = 0; i < (int)w.size(); i++)
        {
            int x = w[i];
            d[x] = e / x;
            for (int j = 0; j < i; j++)
            {
                int y = w[j];
                if (y % x == 0)
                {
                    d[x] -= d[y];
                }
            }
            if (x < e)
            {
                ans = (ans + d[x] * (lcm(x, c) % MOD)) % MOD;
            }
        }
        for (int x : w)
        {
            d[x] = 0;
        }
    }
    cout << ans << endl;
}