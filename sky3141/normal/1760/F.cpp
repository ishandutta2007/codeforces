#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



void solve()
{
    int n;
    LL c;
    int d;
    cin >> n >> c >> d;
    vector<LL> a(max(n, d) + 1), s(max(n, d) + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend() - 1);
    for (int i = 1; i <= max(n, d); ++i)
    {
        s[i] = s[i - 1] + a[i];
    }
    if (a[1] * d < c)
    {
        cout << "Impossible\n";
        return;
    }
    for (int k = 1; k <= d; ++k)
    {
        LL t = s[k] * (d / k) + s[d % k];
        if (t < c)
        {
            cout << k - 2 << '\n';
            return;
        }
    }
    cout << "Infinity\n";
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