#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, x, y, d;
    cin >> t;
    while(t--)
    {
        cin >> n >> x >> y >> d;
        int ans = 2e9;
        if(x % d == y % d)
            ans = abs(x - y)/d;
        if(y % d == 1)
        {
            ans = min(ans, (x + d - 1)/d + (y - 1)/d);
        }
        if(y % d == n % d)
        {
            ans = min(ans, (n + d - 1 - x)/d + (n - y)/d);
        }
        if(ans == 2000000000)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
}