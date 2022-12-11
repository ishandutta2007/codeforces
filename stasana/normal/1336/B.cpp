#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef int64_t ll;

const ll INF = (ll)8e18 + 666;

ll get(vector<ll>& a, vector<ll>& b, vector<ll>& c) {
    ll result = INF;
    ll ptr_a = 0;
    ll ptr_c = 0;
    for (ll i : b) {
        while (ptr_a + 1 < (ll)a.size() && a[ptr_a + 1] <= i) {
            ++ptr_a;
        }
        while (ptr_c + 1 < (ll)c.size() && c[ptr_c] < i) {
            ++ptr_c;
        }
        if (c[ptr_c] < i) {
            continue;
        }
        if (a[ptr_a] > i) {
            continue;
        }
        ll x = i;
        ll y = a[ptr_a];
        ll z = c[ptr_c];
        result = min(result, (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x));
    }
    return result;
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    vector<ll> b(m);
    vector<ll> c(k);
    for (ll& i : a) {
        cin >> i;
    }
    for (ll& i : b) {
        cin >> i;
    }
    for (ll& i : c) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    ll result = INF;
    result = min(result, get(a, b, c));
    result = min(result, get(c, b, a));
    result = min(result, get(b, a, c));
    result = min(result, get(c, a, b));
    result = min(result, get(a, c, b));
    result = min(result, get(b, c, a));
    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    for (ll id = 0; id < n; ++id) {
        solve();
    }

    return 0;
}