#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        ll x = min(a, b);
        ll y = max(x << 1, max(a, b));
        printf("%lld\n", y * y);
    }
}