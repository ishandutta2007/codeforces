#include <bits/stdc++.h>

using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const ll N = 1e6 + 34;

ll go(ll l1, ll r1, ll l2, ll r2) {
    return max(0ll, min(r1, r2) - max(l1, l2) + 1);
}

int main() {
    init();

    ll l1, r1, l2, r2, k;
    cin >> l1 >> r1 >> l2 >> r2 >> k;

    if (l1 <= k && k <= r1)
        cout << go(l1, k - 1, l2, r2) + go(k + 1, r1, l2, r2);
    else
        cout << go(l1, r1, l2, r2);

    return 0;
}