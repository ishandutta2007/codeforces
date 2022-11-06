#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

using LL = long long;

constexpr int MAXN = 500000 + 9;

int n;
LL a[MAXN];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    map<LL, int, greater<LL>> mp{{0, 0}};
    int cur, last = 0;
    for (int i = 1; i <= n; ++i)
    {
        cur = last - 1;
        if (auto it = mp.upper_bound(a[i]); it != mp.end())
        {
            cur = max(cur, i - it->second);
        }
        if (a[i] == a[i - 1])
            cur = max(cur, last);
        int waste = i - cur;
        auto it = mp.lower_bound(a[i]);
        if (it == mp.end() || waste < it->second)
        {
            it = mp.insert_or_assign(a[i], waste).first;
            while (it != mp.begin())
            {
                --it;
                if (it->second >= waste)
                {
                    auto tmp = it;
                    ++tmp;
                    mp.erase(it);
                    it = tmp;
                }
                else
                {
                    break;
                }
            }
        }
        last = cur;
    }
    cout << cur << '\n';
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