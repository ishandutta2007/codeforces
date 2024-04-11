#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int k = 0, l = 0;
        int a[100005];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll d[100005], e[100005];
        for(int i = 0; i < n; i++)
        {
            if(a[i])
            {
                cin >> d[k++];
            }
            else
            {
                cin >> e[l++];
            }
        }
        sort(d, d + k, greater<ll>());
        sort(e, e + l, greater<ll>());
        ll ans = 0;
        if(k < l)
        {
            for(int i = 0; i < k; i++)
            {
                ans += d[i] * 2 + e[i] * 2;
            }
            for(int i = k; i < l; i++)
            {
                ans += e[i];
            }
        }
        else if(k > l)
        {
            for(int i = 0; i < l; i++)
            {
                ans += d[i] * 2 + e[i] * 2;
            }
            for(int i = l; i < k; i++)
            {
                ans += d[i];
            }
        }
        else
        {
            for(int i = 0; i < k; i++)
            {
                ans += d[i] * 2 + e[i] * 2;
            }
            ans -= min(d[k - 1], e[l - 1]);
        }
        cout << ans << endl;
    }
}