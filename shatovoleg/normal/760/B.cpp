#include <iostream>

using namespace std;

typedef long long ll;

ll n, k;

ll count(ll l, ll r)
{
    if (r < l)
        swap(r, l);
    ll n = r - l + 1;
    return n * l + (((n - 1) * n) / 2);
}

ll max(ll a, ll b)
{
    if (a > b)
        return a;
    return b;
}

ll min(ll a, ll b)
{
    if (a < b)
        return a;
    return b;
}

ll count(ll amnt)
{
    if (n == 1)
        return amnt;
    if (amnt == 1)
        return n;
    int r = min(n, k + amnt - 1), l = max(1, k - amnt + 1);
    int v_l, v_r;
    if (l != 1)
        v_l = 1;
    else
        v_l = amnt + l - k;
    if (r != n)
        v_r = 1;
    else
        v_r = amnt + k - n;
    ll ans = 0;
    ans += l - 1;
    ans += n - r;
    ans += count(v_l, amnt);
    ans += count(v_r, amnt);
//    if (v_l != amnt && v_r != amnt)
        ans -= amnt;
    return ans;
}

int main()
{
//    while (true)
//    {
//        cin >> n >> k;
//        int m;
//        cin >> m;
//        cout << count(m) << endl;
//    }
    ll m;
    cin >> n >> m >> k;
    ll l = 0, r = m + 1, c;
    while (r - l > 1)
    {
        c = (r + l) / 2;
        if (count(c) > m)
            r = c;
        else
            l = c;
    }
    cout << l << endl;
}