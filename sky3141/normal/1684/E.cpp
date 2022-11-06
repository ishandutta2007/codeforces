#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
#include <vector>

using namespace std;

using LL = long long;

constexpr int MAXN = 100000 + 9;

int n, k;
int a[MAXN];
int cnt[MAXN];

void solve()
{
    cin >> n >> k;
    fill(cnt, cnt + n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] < n)
            ++cnt[a[i]];
    }
    int tmp = k, res = n;
    for (int i = 0; i < n; ++i)
    {
        if (!cnt[i])
        {
            if (tmp > 0)
                --tmp;
            else
            {
                res = i;
                break;
            }
        }
    }
    map<int, int> mp;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] >= res)
            ++mp[a[i]];
    }
    vector<pair<int, int>> vec(mp.begin(), mp.end());
    sort(vec.begin(), vec.end(), [](auto &a, auto &b){ return a.second < b.second; });
    int ans = vec.size();
    for (auto &p : vec)
    {
        if (k >= p.second)
        {
            --ans;
            k -= p.second;
        }
    }
    cout << ans << '\n';
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