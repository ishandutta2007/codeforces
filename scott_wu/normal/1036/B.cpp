#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    ll q, n, m, k;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> n >> m >> k;
        if (k < n || k < m)
        {
            cout << "-1\n";
            continue;
        }

        for (ll ans = k; ans >= 0; ans--)
        {
            if ((k - ans) % 2 == (n + m) % 2)
            {
                if (ans < k || (n % 2 == k % 2))
                {
                    cout << ans << "\n";
                    break;
                }
            }
        }
    }
}