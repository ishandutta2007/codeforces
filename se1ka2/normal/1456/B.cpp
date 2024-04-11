#include <iostream>
using namespace std;

const int INF = 100000000;

int main()
{
    int n;
    cin >> n;
    int a[200005];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n > 65)
    {
        cout << 1 << endl;
        return 0;
    }
    int ans = INF;
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        for (int l = i; l >= 0; l--)
        {
            x ^= a[l];
            int y = 0;
            for (int r = i + 1; r < n; r++)
            {
                y ^= a[r];
                if (x > y)
                {
                    ans = min(ans, r - l - 1);
                }
            }
        }
    }
    if (ans == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}