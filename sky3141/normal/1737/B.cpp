#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;

LL srt(LL x)
{
    LL l = 1, r = sqrt(x) + 5;
    while (l < r)
    {
        LL mid = (l + r + 1) / 2;
        if (mid * mid > x)
        {
            r = mid - 1;
        }
        else
        {
            l = mid;
        }
    }
    return l;
}

LL calc(LL r)
{
    if (r == 0)
        return 0;
    LL s = srt(r);
    LL res = (s - 1) * 3;
    for (LL t = s * s; t < s * s + 3 * s; t += s)
    {
        if (t <= r)
            ++res;
    }
    return res;
}

void solve()
{
    LL l, r;
    cin >> l >> r;
    cout << calc(r) - calc(l - 1) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}