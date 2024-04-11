#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[200005];
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
            a[i]--;
        }
        sort(a, a + m);
        priority_queue<int> que;
        for (int i = 0; i < m; i++)
        {
            que.push(((a[(i + 1) % m] + n - a[i] - 1) % n));
        }
        int ans = 0;
        int i = 0;
        while (que.size())
        {
            int x = que.top();
            que.pop();
            if (x == i + 1)
            {
                ans += 1;
            }
            else
            {
                ans += max(0, x - (i + 1));
            }
            i += 4;
        }
        cout << n - ans << endl;
    }
}