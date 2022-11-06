#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    for (auto &x : b)
    {
        cin >> x;
    }
    int cnt1 = count(a.begin(), a.end(), 1), cnt2 = count(b.begin(), b.end(), 1);
    int t = 0;
    for (int i = 0; i < n; ++i)
    {
        t += a[i] != b[i];
    }
    int ans = min(t, abs(cnt1 - cnt2) + 1);
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