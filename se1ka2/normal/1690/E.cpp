#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        ll a[200005];
        int b[1005]{0};
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            ans += a[i] / k;
            b[a[i] % k]++;
        }
        int r = k - 1;
        for (int i = 0; i < k; i++)
        {
            while (b[i] && i + r >= k)
            {
                if(i == r)
                {
                    ans += b[i] / 2;
                    b[i] %= 2;
                    break;
                }
                int d = min(b[i], b[r]);
                b[i] -= d;
                b[r] -= d;
                ans += d;
                if (b[r] == 0)
                {
                    r--;
                }
            }
        }
        cout << ans << endl;
    }
}