#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        ll a[200005];
        P p[200005];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            p[i] = P(a[i] + i, i);
        }
        sort(p, p + n, greater<P>());
        bool b[200005];
        for(int i = 0; i < n; i++)
        {
            b[i] = false;
        }
        for(int i = 0; i < k; i++)
        {
            b[p[i].second] = true;
        }
        int c = 0;
        ll ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(!b[i])
            {
                ans = ans + a[i] + c;
            }
            else
            {
                c++;
            }
        }
        cout << ans << "\n";
    }
}