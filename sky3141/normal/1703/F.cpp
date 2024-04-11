#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1), b;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (a[i] < i)
            b.push_back(a[i]);
    }
    sort(b.begin(), b.end(), [](int a, int b){ return a > b; });
    LL ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] < i)
        {
            while (!b.empty() && b.back() <= i)
            {
                b.pop_back();
            }
            ans += b.size();
        }
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