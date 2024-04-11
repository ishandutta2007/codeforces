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
    string s;
    cin >> n;
    cin >> s;
    LL ans = 0;
    priority_queue<int> que;
    for (int i = 0; i < n; ++i)
    {
        int l = i, r = n - i - 1;
        if (s[i] == 'L')
        {
            ans += l;
            que.push(r - l);
        }
        else
        {
            ans += r;
            que.push(l - r);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (que.top() > 0)
        {
            ans += que.top();
            que.pop();
        }
        cout << ans << ' ';
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