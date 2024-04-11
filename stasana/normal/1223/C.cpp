#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef int64_t ll;

inline void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

inline void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; ++i) {
        cin >> arr[i];
        arr[i] /= 100;
    }
    ll x, a;
    ll y, b;
    cin >> x >> a;
    cin >> y >> b;
    if (x < y) {
        swap(x, y);
        swap(a, b);
    }
    sort(arr.begin(), arr.end());
    arr.emplace_back(0);
    reverse(arr.begin(), arr.end());
    for (ll i = 1; i <= n; ++i) {
        arr[i] = arr[i - 1] + arr[i];
    }
    ll c = a * b / gcd(a, b);
    ll k;
    cin >> k;
    ll left = 0;
    ll right = n + 1;
    while (right - left > 1) {
        ll mid = (left + right) / 2;
        ll k1 = mid / c;
        ll k2 = mid / a - k1;
        ll k3 = mid / b - k1;
        ll sum = arr[k1] * (x + y) + (arr[k2 + k1] - arr[k1]) * x + (arr[k3 + k2 + k1] - arr[k2 + k1]) * y;
        if (sum >= k) {
            right = mid;
        } else {
            left = mid;
        }
    }
    if (right == n + 1) {
        cout << -1 << endl;
    } else {
        cout << right << endl;
    }
}

int main() {
    start();
    int n;
    cin >> n;
    while (n) {
        --n;
        solve();
    }
    return 0;
}