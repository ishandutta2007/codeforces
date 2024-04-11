#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n, d, m;
    cin >> n >> d >> m;
    ll x[100005], y[100005];
    int k = 0, l = 0;
    for(int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        if(a > m)
        {
            x[k++] = a;
        }
        else
        {
            y[l++] = a;
        }
    }
    sort(x, x + k, greater<ll>());
    sort(y, y + l, greater<ll>());
    ll s[100005], t[100005];
    s[0] = 0;
    for(int i = 1; i <= k; i++)
    {
        s[i] = s[i - 1] + x[i - 1];
    }
    t[0] = 0;
    for(int i = 1; i <= l; i++)
    {
        t[i] = t[i - 1] + y[i - 1];
    }
    ll ans = 0;
    for(int i = 0; i <= k; i++)
    {
        int e = max(0, d * (i - 1) - (k - i));
        if(e > l)
        {
            break;
        }
        ans = max(ans, s[i] + t[l - e]);
    }
    cout << ans << endl;
}