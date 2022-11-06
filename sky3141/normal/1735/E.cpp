#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    vector<int> d1(n), d2(n);
    for (auto &x : d1)
        cin >> x;
    for (auto &x : d2)
        cin >> x;
    sort(d1.begin(), d1.end());
    sort(d2.begin(), d2.end());
    auto try_match = [&](int dist) -> vector<int>
    {
        auto cd1 = d1, cd2 = d2;
        auto it1 = cd1.rbegin(), it2 = cd2.rbegin();
        auto rit1 = cd1.rbegin(), rit2 = cd2.rbegin();
        vector<int> res;
        while (true)
        {
            while (rit1 != cd1.rend() && *rit1 < dist)
                ++rit1;
            while (rit2 != cd2.rend() && *rit2 < dist)
                ++rit2;
            if (rit1 == cd1.rend() && rit2 == cd2.rend())
                break;
            int t1 = rit1 == cd1.rend() ? -1 : *rit1;
            int t2 = rit2 == cd2.rend() ? -1 : *rit2;
            if (t1 > t2)
            {
                while (it2 != cd2.rend() && (*it2 == -1 || *it2 > t1 - dist))
                    ++it2;
                if (it2 != cd2.rend() && t1 - dist == *it2)
                {
                    res.push_back(*rit1);
                    *rit1 = *it2 = -1;
                }
                else
                {
                    return {};
                }
            }
            else
            {
                while (it1 != cd1.rend() && (*it1 == -1 || *it1 > t2 - dist))
                    ++it1;
                if (it1 != cd1.rend() && t2 - dist == *it1)
                {
                    res.push_back(-*it1);
                    *rit2 = *it1 = -1;
                }
                else
                {
                    return {};
                }
            }
        }
        auto t = cd2.rbegin();
        for (auto x : cd1)
        {
            if (x != -1)
            {
                while (t != cd2.rend() && *t == -1)
                    ++t;
                if (t != cd2.rend() && x + *t == dist)
                {
                    res.push_back(x);
                    ++t;
                }
                else
                {
                    return {};
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    };
    vector<int> dist;
    dist.reserve(2 * n);
    for (auto x : d2)
    {
        dist.push_back(d1[0] + x);
        dist.push_back(abs(d1[0] - x));
    }
    sort(dist.begin(), dist.end());
    dist.erase(unique(dist.begin(), dist.end()), dist.end());
    for (auto d : dist)
    {
        auto ans = try_match(d);
        if (!ans.empty())
        {
            int B = -min(ans[0], 0);
            cout << "YES\n";
            for (auto &x : ans)
            {
                cout << x + B << ' ';
            }
            cout << '\n';
            cout << B << ' ' << B + d << '\n';
            return;
        }
    }
    cout << "NO\n";
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