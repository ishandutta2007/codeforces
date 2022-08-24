#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;
typedef long long ll;
const int MAXD = 60;

int mob[MAXD];
ll mhi[MAXD];

bool prime (int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

ll gm (int x, ll v, ll hi)
{
    ll lo = 1;
    while (lo < hi)
    {
        ll mid = (lo + hi + 1) / 2;
        ll res = 1;
        bool bad = false;
        for (int i = 0; i < x; i++)
        {
            if ((res * mid) > v || (v / mid) < res)
            {
                bad = true;
                break;
            }
            res *= mid;
        }
        if (bad)
            hi = mid - 1;
        else
            lo = mid;
    }
    //cout << "gm " << x << " " << v << " " << lo << "\n";
    return lo - 1;
}

ll gn (int x, ll v)
{
    ll lo = 1, hi = mhi[x];
    while (lo < hi)
    {
        ll mid = (lo + hi + 1) / 2;
        ll res = mid;
        bool bad = false;
        for (int i = 0; i < x; i++)
        {
            if (res > v)
            {
                bad = true;
                break;
            }
            res *= mid;
        }
        if (bad)
            hi = mid - 1;
        else
            lo = mid;
    }
    return lo - 1;
}

ll get_ans (ll v)
{
    ll ans = v - 1;
    for (int i = 2; i < 60; i++)
    {
        if (mob[i] != 0)
        {
            ans += mob[i] * (gn (i, v));
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    for (int i = 0; i < 60; i++)
        mob[i] = 1;
    mob[0] = mob[1] = 0;
    for (int i = 2; i < MAXD; i++)
    {
        if (prime (i))
        {
            for (int j = i; j < MAXD; j += i)
                mob[j] = -mob[j];
            for (int j = i * i; j < MAXD; j += i * i)
                mob[j] = 0;
        }
        if (mob[i])
            mhi[i] = gm (i, 1e18, 1e9) + 1;
    }

    int T; cin >> T;
    for (int i = 0; i < T; i++)
    {
        ll x; cin >> x;
        cout << get_ans (x) << "\n";
    }
}