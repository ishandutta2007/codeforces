#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;



vector<int> query(int l, int r)
{
    cout << "? " << l << ' ' << r << endl;
    int len = r - l + 1;
    vector<int> res(len);
    for (auto &x : res)
    {
        cin >> x;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r) / 2;
        auto t = query(l, mid);
        int cnt = 0;
        for (auto &x : t)
        {
            if (l <= x && x <= mid)
                ++cnt;
        }
        if (cnt % 2 == 0)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    cout << "! " << l << endl;
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