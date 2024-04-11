#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

using LL = long long;

constexpr int MAXN = 100000 + 9;

int n;
// int a[MAXN];

void solve()
{
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        ++mp[x];
    }
    using mii = map<int, int>;
    while (n > 1)
    {
        map<int, int> t;
        mii::iterator it;
        for (mii::iterator cit = mp.begin(); cit != mp.end(); ++cit)
        {
            if (cit->second > 1)
            {
                t[0] += cit->second - 1;
            }
            if (cit != mp.begin())
            {
                ++t[cit->first - it->first];
            }
            it = cit;
        }
        mp = std::move(t);
        --n;
    }
    cout << mp.begin()->first << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}