#include <bits/stdc++.h>

typedef long long ll;
const ll MAXN = 1'000'000'000'000'000'000ll;

int
lower_sqrt(ll x)
{
    int l = 0, r = std::min(x + 1, 1'000'000'001ll);
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (1ll * m * m <= x) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

bool is_exact_square(ll x)
{
    int l = lower_sqrt(x);
    return (1ll * l * l == x);
}

int
count_powers(ll x, const std::vector<ll>& pws)
{
    int ans = std::upper_bound(pws.begin(), pws.end(), x) - pws.begin();
    return ans + lower_sqrt(x);
}

int
main()
{
    // Precompute powers of 3, 4, 5, ..., that's not exact sequares
    std::vector<ll> powers_not_2;
    for (int i = 2; MAXN / i / i >= i; ++i) {
        ll cur_val = 1ll * i * i;
        while (MAXN / i >= cur_val) {
            cur_val *= i;
            powers_not_2.push_back(cur_val);
        }
    }
    std::sort(powers_not_2.begin(), powers_not_2.end());
    powers_not_2.erase(std::unique(powers_not_2.begin(), powers_not_2.end()), powers_not_2.end());
    powers_not_2.erase(std::remove_if(powers_not_2.begin(), powers_not_2.end(), is_exact_square), powers_not_2.end());
    // Do some hard work
    std::ios_base::sync_with_stdio(0);
    int q;
    std::cin >> q;
    for (int _ = 0; _ < q; ++_) {
        ll l, r;
        std::cin >> l >> r;
        std::cout << count_powers(r, powers_not_2) - count_powers(l - 1, powers_not_2) << '\n';
    }
    return 0;
}