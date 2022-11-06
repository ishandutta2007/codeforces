#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 500000 + 9;



void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> cnt(N);
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        ++cnt[a];
    }
    for (int i = 1; i < x; ++i)
    {
        cnt[i + 1] += cnt[i] / (i + 1);
        cnt[i] %= i + 1;
        if (cnt[i])
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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