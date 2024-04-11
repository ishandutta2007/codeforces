#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), s(n + 1);
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        ++a[x];
    }
    for (int i = 1; i <= n; ++i)
    {
        s[i] = s[i - 1] + a[i];
    }
    int ans = -100;
    for (int i = 0; i <= n; ++i)
    {
        // int sum = 0;
        bool flag = true;
        deque<int> que;
        for (int j = 1; j <= i; ++j)
        {
            for (int k = 0; k < a[j]; ++k)
                que.push_back(j);
        }
        for (int j = i; j >= 1; --j)
        {
            while (!que.empty() && que.back() > j)
                que.pop_back();
            if (que.empty())
                flag = false;
            else
                que.pop_back();
            if (!que.empty())
                que.pop_front();
        }
        if (flag)
            ans = i;
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