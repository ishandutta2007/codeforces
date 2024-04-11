#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        ll n, k;
        scanf("%lld %lld", &n, &k);

        ll ans = 0;
        for(ll i=1; i*i<=n; i++) {
            if(n % i == 0) {
                if(i <= k) ans = max(ans, i);
                if(n / i <= k) ans = max(ans, n/i);
            }
        }

        printf("%lld\n", n / ans);
    }
}