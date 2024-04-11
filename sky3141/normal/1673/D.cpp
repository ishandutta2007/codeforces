#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int mod = 1000000007;

bool in(LL s, LL e, LL d, LL x)
{
    return x >= s && x <= e && (x - s) % d == 0;
}

LL gcd(LL a, LL b)
{
    return b == 0 ? a : gcd(b, a % b);
}

inline LL lcm(LL a, LL b)
{
    return a * b / gcd(a, b);
}

void solve()
{
    LL bs, bd, bn, be;
    LL cs, cd, cn, ce;
    cin >> bs >> bd >> bn;
    cin >> cs >> cd >> cn;
    be = bs + (bn - 1) * bd;
    ce = cs + (cn - 1) * cd;
    if (!(in(bs, be, bd, cs) && in(bs, be, bd, ce) && cd % bd == 0))
    {
        cout << "0\n";
        return;
    }
    if (!(in(bs, be, bd, cs - cd) && in(bs, be, bd, ce + cd)))
    {
        cout << "-1\n";
        return;
    }
    vector<int> fac;
    for (int i = 1; i * i <= cd; ++i)
    {
        if (cd % i == 0)
        {
            if (i * i == cd)
            {
                fac.push_back(i);
            }
            else
            {
                fac.push_back(i);
                fac.push_back(cd / i);
            }
        }
    }
    LL ans = 0;
    for (int td : fac)
    {
        if (td == cd)
        {
            ans += 1;
            ans %= mod;
        }
        else if (lcm(bd, td) == cd)
        {
            LL tmp = cd / td;
            ans += tmp * tmp;
            ans %= mod;
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        solve();
    }

    return 0;
}