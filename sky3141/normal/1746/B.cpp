#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> ones, zeros;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i])
            ones.push_back(i);
        else
            zeros.push_back(i);
    }
    reverse(ones.begin(), ones.end());
    int ans = 0;
    while (!ones.empty() && !zeros.empty() && ones.back() < zeros.back())
    {
        ++ans;
        ones.pop_back();
        zeros.pop_back();
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