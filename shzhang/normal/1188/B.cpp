#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int n, p, k;
#define ll long long
#define mul(a, b) (((ll)(a) * (ll)(b)) % p)

int fpow(int base, int exponent)
{
    int ans = 1;
    int cur = base;
    while (exponent) {
        if (exponent & 1) ans = mul(ans, cur);
        cur = mul(cur, cur); exponent >>= 1;
    }
    return ans;
}

int seq[300005];

int main()
{
    scanf("%d%d%d", &n, &p, &k);
    for (int i = 1; i <= n; i++) scanf("%d", seq + i);
    for (int i = 1; i <= n; i++) {
        seq[i] = (((fpow(seq[i], 4) - mul(seq[i], k)) % p) + p) % p;
    }
    sort(seq + 1, seq + n + 1);
    int curl = 1;
    int curr = 1;
    ll ans = 0;
    while (1) {
        while (curr < n && seq[curr + 1] == seq[curl]) curr++;
        ll siz = curr - curl + 1;
        ans += (siz * (siz - 1ll)) / 2ll;
        curr++; curl = curr; if (curl > n) break;
    }
    cout << ans;
    return 0;
}