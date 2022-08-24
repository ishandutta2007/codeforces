#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N, K;

ll res;

ll test (ll x)
{
    ll p2 = 1;
    ll ans = 0;
    while (p2 * x <= N)
    {
        ll hi = min (N, p2 * (x + 1) - 1);
        ans += hi - p2 * x + 1;
        p2 *= 2;
    }
    return ans;
}

ll vtest (ll x)
{
    if (x % 2 == 0) return test (x) + test (x + 1);
    return test (x);
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N >> K;
    res = 1;

    ll cn = N;
    while (cn)
    {
        for (ll i = 0; i <= 10; i++)
        {
            if (i >= cn) continue;
            if (vtest (cn - i) >= K)
            {
                res = max (res, cn - i);
            }
        }
        cn /= 2;
    }
    cout << res << "\n";
}