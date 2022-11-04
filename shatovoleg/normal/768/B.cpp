#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <complex>
#include <fstream>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ld = long double;

ll count_len(ll n)
{
    int ans = 0;
    while (n)
    {
        ++ans;
        n >>= 1;
    }
    return (1LL << ans) - 1;
}

ll ans(ll n, ll l, ll r, ll len)
{
    if (!n)
        return 0;
    if (l >= len || r <= 0)
        return 0;
    if (l <= 0 && r >= len)
        return n;
    ll res = ans(n >> 1, l, r, len >> 1);
    if (r > (len >> 1) && l <= (len >> 1))
        res += (n & 1);
    res += ans(n >> 1, l - (len >> 1) - 1, r - (len >> 1) - 1, len >> 1);
    return res;
}

int main()
{
    ll n, l, r;
    cin >> n >> l >> r;
    --l;
    cout << ans(n, l, r, count_len(n)) << endl;
//    while (1)
//    {
//        int v;
//        cin >> v;
//        cout << count_len(v) << endl;
//    }
}