#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    // set<int> st;
    map<int, int> mp;
    for (auto &x : a)
    {
        cin >> x;
        ++mp[x];
    }
    if (mp.size() > 5)
    {
        cout << "no\n";
        return;
    }
    vector<int> ta;
    for (auto &[k, v] : mp)
    {
        int t = min(v, 3);
        for (int i = 0; i < t; ++i)
            ta.push_back(k);
    }
    int tn = ta.size();
    for (int i = 0; i < tn; ++i)
    {
        for (int j = i + 1; j < tn; ++j)
        {
            for (int k = j + 1; k < tn; ++k)
            {
                if (!mp.contains(ta[i] + ta[j] + ta[k]))
                {
                    cout << "no\n";
                    return;
                }
            }
        }
    }
    cout << "yes\n";
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