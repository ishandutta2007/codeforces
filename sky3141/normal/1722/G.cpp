#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    vector<int> ans(n);
    constexpr int B = 1 << 20;
    int t = 0;
    for (int i = 1; i < n; ++i)
    {
        ans[i] = i;
        t ^= i;
    }
    ans[0] = B | t;
    for (int i = 1; i < n; ++i)
    {
        if (ans[i] != t)
        {
            ans[i] |= B;
            break;
        }
    }
    for (auto &x : ans)
    {
        cout << x << ' ';
    }
    cout << '\n';
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
    
    return 0;
}