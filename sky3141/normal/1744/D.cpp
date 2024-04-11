#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



inline int lowbit(int x)
{
    return x & (-x);
}

int lg2(int x)
{
    x = lowbit(x);
    for (int i = 0; ; ++i)
    {
        if ((1 << i) == x)
            return i;
    }
}

void solve()
{
    int n;
    cin >> n;
    // vector<int> a(n);
    int sum = 0;
    vector<int> a;
    a.reserve(n);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        sum += lg2(x);
        a.push_back(lg2(i));
    }
    int ans = 0;
    sort(a.rbegin(), a.rend());
    for (auto x : a)
    {
        if (sum >= n)
            break;
        sum += x;
        ++ans;
    }
    if (sum < n)
        ans = -1;
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