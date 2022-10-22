#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll n, ll m, ll &x, ll &y)
{
    if (m == 0)
    {
        x = 1;
        y = 0;
        return n;
    }
    ll g = gcd(m, n % m, y, x);
    y -= n / m * x;
    return g;
}

ll a[300005], b[300005];
ll d[300005];
ll s[300005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        d[i] = a[i] - b[i];
    }
    sort(d, d + n, greater<ll>());
    s[0] = 0;
    for (int i = 0; i < n; i++)
    {
        s[0] += b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + d[i - 1];
    }
    ll l;
    for (l = 0; l < n; l++)
    {
        if (d[l] <= 0)
        {
            break;
        }
    }
    int m;
    cin >> m;
    while (m--)
    {
        ll a, b;
        cin >> a >> b;
        ll x, y;
        ll g = gcd(a, b, x, y);
        if (n % g)
        {
            cout << -1 << "\n";
            continue;
        }
        x *= n / g;
        y *= n / g;
        a /= g;
        b /= g;
        if(x >= 0)
        {
            ll d = x / b;
            x -= b * d;
            y += a * d;
        }
        else
        {
            ll d = (abs(x) + b - 1) / b;
            x += b * d;
            y -= a * d;
        }
        ll d = (l - a * g * x) / (a * g * b);
        x += b * d;
        y -= a * d;
        ll ans = -1;
        for (int i = 0; i < 2; i++)
        {
            if (x >= 0 && y >= 0)
            {
                ans = max(ans, s[a * g * x]);
            }
            x += b;
            y -= a;
        }
        cout << ans << "\n";
    }
}