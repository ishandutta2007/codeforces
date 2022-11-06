#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+7;

ll fnc(ll n, ll lcm, ll x)
{
    ll z = n / lcm;
    ll ans = z * x;
    z *= lcm;
    ans += min(n - z + 1, x);
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int a, b, q;
        scanf("%d %d %d", &a, &b, &q);
        if(a > b) swap(a, b);
        int lcm = a * b / __gcd(a, b);
        while(q--) {
            ll l, r;
            scanf("%lld %lld", &l, &r);
            printf("%lld ", r-l+1-fnc(r,lcm,b)+fnc(l-1,lcm,b));
        }
        puts("");
    }
}