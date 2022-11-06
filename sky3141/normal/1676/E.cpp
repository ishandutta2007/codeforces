#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;



void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    sort(a.rbegin(), a.rend());
    for (int i = 1; i < n; ++i)
    {
        a[i] += a[i - 1];
    }
    for (int i = 0; i < q; ++i)
    {
        int x;
        cin >> x;
        int ans = -1;
        int l = 0, r = n;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (a[mid] < x)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
                ans = mid + 1;
            }
        }
        cout << ans << '\n';
    }
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