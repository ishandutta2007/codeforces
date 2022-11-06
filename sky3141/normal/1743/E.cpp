#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;
constexpr LL INF = 1000000000000000000;

struct Item
{
    LL d;
    LL t;
};

void solve()
{
    int p1, p2;
    LL t1, t2;
    int h, s;
    cin >> p1 >> t1;
    cin >> p2 >> t2;
    cin >> h >> s;
    vector<LL> w(h + 1, INF);
    auto getdamage = [&](LL t)
    {
        LL c1 = t / t1, c2 = t / t2;
        LL res = c1 * (p1 - s) + c2 * (p2 - s);
        if (c1 && c2)
            res += s;
        return res;
    };
    for (int i = 1; i <= h; ++i)
    {
        LL t = i * t1, d = min(getdamage(t), (LL)h);
        w[d] = min(w[d], t);
        t = i * t2, d = min(getdamage(t), (LL)h);
        w[d] = min(w[d], t);
    }
    for (int i = h - 1; i >= 0; --i)
    {
        w[i] = min(w[i], w[i + 1]);
    }
    vector<LL> f(h + 1, INF);
    f[0] = 0;
    for (int i = 1; i <= h; ++i)
    {
        for (int j = i; j <= h; ++j)
        {
            f[j] = min(f[j], f[j - i] + w[i]);
        }
    }
    cout << f[h] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
}