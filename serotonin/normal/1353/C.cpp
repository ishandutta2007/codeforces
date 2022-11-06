#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz], b[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        n >>= 1;
        ll ans = 8 * n * (n + 1) * (2 * n + 1) / 6;
        printf("%lld\n", ans);
    }
}