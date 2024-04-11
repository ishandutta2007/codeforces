#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        int sx, sy;
        int d;
        cin >> n >> m >> sx >> sy >> d;
        int ans = -1;
        if (sx - d > 1 && sy + d < m)
        {
            ans = n + m - 2;
        }
        if (sx + d < n && sy - d > 1)
        {
            ans = n + m - 2;
        }
        if ((n - sx) + (m - sy) <= d)
        {
            ans = -1;
        }
        cout << ans << endl;
    }
}