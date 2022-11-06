#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

using LL = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    LL ans = 0;
    priority_queue<int, vector<int>, greater<int>> que;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (!que.empty() && que.top() < x)
        {
            ans += x - que.top();
            que.pop();
            que.push(x);
        }
        que.push(x);
    }

    cout << ans << '\n';

    return 0;
}