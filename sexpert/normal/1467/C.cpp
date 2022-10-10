#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    vector<ll> v1(a), v2(b), v3(c);

    ll ans = 0;

    for(auto &x : v1) {
        cin >> x;
        ans += x;
    }

    for(auto &x : v2) {
        cin >> x;
        ans += x;
    }

    for(auto &x : v3) {
        cin >> x;
        ans += x;
    }

    ll tk = accumulate(v1.begin(), v1.end(), 0LL);
    tk = min(tk, accumulate(v2.begin(), v2.end(), 0LL));
    tk = min(tk, accumulate(v3.begin(), v3.end(), 0LL));

    ll p, q, r;
    p = *min_element(v1.begin(), v1.end());
    q = *min_element(v2.begin(), v2.end());
    r = *min_element(v3.begin(), v3.end());

    //cout << tk << '\n';
    //cout << ans << '\n';

    tk = min(tk, p + q);
    tk = min(tk, q + r);
    tk = min(tk, r + p);

    //cout << p << " " << q << " " << r << '\n';

    cout << ans - 2LL * tk << '\n';
}