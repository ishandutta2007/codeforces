#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

ll a[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        ll n, k, tot = 0;
        scanf("%lld %lld", &n, &k);
        for(int i=0; i<n; i++) scanf("%lld", &a[i]);
        sort(a, a+n, greater<ll>());

        int ans = 0;
        for(int i=0; i<n; i++) {
            tot += a[i];
            if(tot / (i+1) >= k) ans = i+1;
        }

        printf("%d\n", ans);
    }
}