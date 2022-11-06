#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

using LL = long long;

constexpr int MAXN = 100000 + 9;

int n;
int a[MAXN];
int lstp[MAXN];
int l2[MAXN];
int kind[MAXN];

void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    fill(lstp, lstp + n + 1, -1);
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (lstp[a[i]] == -1)
            ++cnt;
        kind[i] = cnt;
        lstp[a[i]] = i;
    }
    int mx = -1;
    for (int i = 0; i < n; ++i)
    {
        mx = max(mx, lstp[a[i]]);
        l2[i] = mx;
    }
    int i;
    for (i = n - 2; i >= 0; --i)
    {
        bool flag = false;
        if (a[i] > a[i + 1])
        {
            flag = true;
            while (l2[i] > i)
                i = l2[i];
        }
        if (flag)
            break;
    }
    int ans;
    if (i == -1)
    {
        ans = 0;
    }
    else
    {
        ans = kind[i];
    }
    cout << ans << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}