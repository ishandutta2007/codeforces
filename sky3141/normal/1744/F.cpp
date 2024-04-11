#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;

LL c2(LL a, LL b, LL limit)
{
    if (limit > a - 1 + b - 1)
        return 0;
    if (limit < 0)
        return a * b;
    if (a < b)
        swap(a, b);
    if (limit < b)
        return a * b - limit * (limit + 1) / 2;
    if (limit < a)
        return a * b - (b * (b + 1) / 2 + (limit - b) * b);
    LL t = a + b - 1 - limit;
    return t * (t + 1) / 2;
}

LL calc(LL a, LL b, LL limit)
{
    return a * b - c2(a, b, limit);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        p[x] = i;
    }
    int l = n - 1, r = 0;
    LL ans = 1;
    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            if (p[i] < l)
            {
                int a = l - p[i], b = n - r, limit = 2 * i + 1 - (r - l + 1);
                ans += calc(a, b, limit);
            }
            if (p[i] > r)
            {
                int a = l + 1, b = p[i] - r, limit = 2 * i + 1 - (r - l + 1);
                ans += calc(a, b, limit);
            }
        }
        l = min(l, p[i]);
        r = max(r, p[i]);
    }
    cout << ans << '\n';
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