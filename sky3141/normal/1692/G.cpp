#include <bits/stdc++.h>

using namespace std;

using LL = long long;



void solve()
{
    int n, k;
    cin >> n >> k;
    ++k;
    vector<LL> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    int lastbad = n;
    int ans = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = i + 1; j < min(i + 31, n); ++j)
        {
            if (a[i] >= (a[j] << (j - i)))
                lastbad = min(lastbad, j);
        }
        if (lastbad - i >= k)
            ++ans;
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