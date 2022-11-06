#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;

int n;
int a[MAXN], b[MAXN];
int del[MAXN];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
    }
    fill(del, del + n + 1, 0);
    int cur = n;
    for (int i = n; i >= 1; --i)
    {
        if (a[cur] != b[i] && i < n && b[i] == b[i + 1])
        {
            ++del[b[i]];
            continue;
        }
        while (a[cur] != b[i])
        {
            if (!del[a[cur]])
            {
                cout << "No\n";
                return;
            }
            --del[a[cur]];
            --cur;
        }
        --cur;
    }
    cout << "Yes\n";
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