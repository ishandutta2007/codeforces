#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        ll x;
        cin >> n >> x;
        ll a[200005];
        ll l = 1000000000, r = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(max(r, a[i]) - min(l, a[i]) > x * 2)
            {
                ans++;
                l = 1000000000;
                r = 0;
            }
            l = min(l, a[i]);
            r = max(r, a[i]);
        }
        cout << ans << endl;
    }
}