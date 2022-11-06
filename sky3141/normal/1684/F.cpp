#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <utility>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;

int n, m;
int a[MAXN];
pair<int, int> seg[MAXN];
int minl[MAXN];
int maxr[MAXN];

void solve()
{
    cin >> n >> m;
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    fill(maxr, maxr + n + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        cin >> seg[i].first >> seg[i].second;
        maxr[seg[i].first] = max(maxr[seg[i].first], seg[i].second);
    }
    for (int i = 1; i <= n; ++i)
    {
        maxr[i] = max(maxr[i], maxr[i - 1]);
    }
    {
        set<int> s;
        for (int r = n, l = n; r >= 1; --r)
        {
            while (l >= 1 && s.insert(a[l]).second)
            {
                --l;
            }
            minl[r] = l + 1;
            s.erase(a[r]);
        }
    }
    int r = 0;
    for (int i = 0; i < m; ++i)
    {
        if (minl[seg[i].second] > seg[i].first)
        {
            r = max(r, minl[seg[i].second] - 1);
        }
    }
    if (r == 0)
    {
        cout << "0\n";
        return;
    }
    int ans = r;
    for (int l = 1; l <= n - 1; ++l)
    {
        const vector<int> &vec = mp[a[l]];
        int pos = lower_bound(vec.begin(), vec.end(), l) - vec.begin() - 1;
        if (pos >= 0 && maxr[vec[pos]] >= l)
            break;
        vector<int>::const_iterator it = upper_bound(vec.begin(), vec.end(), r);
        if (it != vec.end() && maxr[l] >= *it)
            r = *it;
        ans = min(ans, r - l);
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