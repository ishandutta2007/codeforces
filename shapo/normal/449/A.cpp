#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int
main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    ll res = -1;
    if (n + m - 2 >= k) {
        for (ll i = 1; i * i <= 2 * n; ++i) {
            ll left_bord = n / (i + 1);
            ll right_bord = n / i - 1;
            right_bord = min(min(right_bord, n - 1), k);
            if (right_bord >= left_bord) {
                ll rest_second = k - right_bord + 1;
                right_bord++;
                res = max(res, 1ll * (n / right_bord) * (m / rest_second));
            }
        }
        for (ll cnt1 = 0; cnt1 * cnt1 <= 2 * n && cnt1 <= k; ++cnt1) {
            ll rest_second = k - cnt1 + 1;
            ll rest_first = cnt1 + 1;
            if (rest_second <= m && rest_first <= n) {
                res = max(res, 1ll * (n / rest_first) * (m / rest_second));
            }
        }
    }
    if (!res) {
        res = -1;
    }
    cout << res << '\n';
    return 0;
}