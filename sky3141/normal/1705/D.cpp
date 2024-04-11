#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;

int n;
char s[MAXN], t[MAXN];

void solve()
{
    cin >> n;
    cin >> s;
    cin >> t;
    if (s[0] != t[0] || s[n - 1] != t[n - 1])
    {
        cout << "-1\n";
        return;
    }
    using pii = pair<int, int>;
    vector<pii> vs, vt;
    for (int i = 0; i < n;)
    {
        while (i < n && s[i] == '0')
            ++i;
        if (i < n)
        {
            int l = i;
            while (i < n && s[i] == '1')
                ++i;
            vs.push_back({l, i});
        }
    }
    for (int i = 0; i < n;)
    {
        while (i < n && t[i] == '0')
            ++i;
        if (i < n)
        {
            int l = i;
            while (i < n && t[i] == '1')
                ++i;
            vt.push_back({l, i});
        }
    }
    if (vs.size() != vt.size())
    {
        cout << "-1\n";
        return;
    }
    LL ans = 0;
    for (int i = 0; i < vs.size(); ++i)
    {
        ans += abs(vs[i].first - vt[i].first) + abs(vs[i].second - vt[i].second);
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