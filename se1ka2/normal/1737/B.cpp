#include <iostream>
using namespace std;
typedef long long ll;

ll solve(ll n)
{
    if (n == 0)
    {
        return 0;
    }
    ll left = 0, right = 2000000000;
    while (right - left > 1)
    {
        ll mid = (right + left) / 2;
        if (mid * mid <= n)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    ll res = (left - 1) * 3 + 1;
    if (n >= left * (left + 1))
    {
        res++;
    }
    if (n >= left * (left + 2))
    {
        res++;
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        cout << solve(r) - solve(l - 1) << endl;
    }
}