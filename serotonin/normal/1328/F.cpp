#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2e5+5;

ll a[sz], cum[sz];

int main()
{
    ll n,k;
    cin >> n >> k;
    for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
    sort(a+1,a+n+1);
    for(int i=1; i<=n; i++) cum[i] = a[i] + cum[i-1];

    ll ans = 1e18, lc, ls, c;
    for(int i=1; i<=n; i++) {
        if(a[i]!=a[i-1]) {
            ll now = (a[i]-1)*(i-1) - cum[i-1];
            ls = now, lc = i-1, c = 1;
        }
        else c++;

        if(a[i]!=a[i+1]) {
            ll rs = (cum[n]-cum[i]) - (a[i]+1)*(n-i);
            ll rc = n-i;
            ll m = k-c;
            if(m<=0) ans = 0;
            else {
                if(rc >= m) ans = min(ans, rs + m);
                if(lc >= m) ans = min(ans, ls + m);
                ans = min(ans, rs + ls + m);
            }
        }
    }

    cout << ans;
}