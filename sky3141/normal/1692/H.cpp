#include <bits/stdc++.h>

using namespace std;

using LL = long long;



void solve()
{
    int n;
    cin >> n;
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        mp[x].push_back(i);
    }
    int ansa, ansl, ansr, anscnt = 0;
    for (auto &[key, vec] : mp)
    {
        int l, last = -100, cur = 0;
        for (auto &pos : vec)
        {
            if (cur - (pos - last - 1) + 1 < 1)
            {
                l = pos;
                cur = 1;
            }
            else
            {
                cur = cur - (pos - last - 1) + 1;
            }
            last = pos;
            if (cur > anscnt)
            {
                anscnt = cur;
                ansa = key;
                ansl = l;
                ansr = pos;
            }
        }
    }
    cout << ansa << ' ' << ansl << ' ' << ansr << '\n';
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