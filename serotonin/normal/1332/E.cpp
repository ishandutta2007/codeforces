#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

ll bigmod(ll b, ll n)
{
    ll ans = 1;
    b %= mod;
    while(n) {
        if(n & 1) ans = (ans * b) % mod;
        n >>= 1;
        b = (b * b) % mod;
    }
    return ans;
}

int main()
{
    ll n, m, l, r, ans;
    cin >> n >> m >> l >> r;

    ll x = r - l + 1, z = n * m;
    ans = bigmod(x, z);
    if(z % 2 == 0) {
        if(x & 1) ans = (ans + 1) % mod;
        ans = ans * bigmod(2, mod - 2) % mod;
    }

    if(ans < 0) ans += mod;
    cout << ans;
}