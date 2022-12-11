#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const ll INF = (ll)2e12 + 41;

ll getLCM(ll a, ll b) {
    if (max(a, b) >= INF) return INF;
    ll g = __gcd(a, b);
    if (a / g >= INF / b) return INF;
    return a / g * b;
    
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    sort(all(a));
    ll mn = a[0];
    ll mx = a.back();
    ll lcm = accumulate(all(a), (ll)1, getLCM);
    if (lcm == mx) {
        lcm *= mn;
        if (lcm > INF) {
            cout << "-1\n";
            return;
        }
    }
    vector<ll> b;
    for (ll i = 2; i * i <= lcm; i++) {
        if (lcm % i) continue;
        b.push_back(i);
        if (i != lcm / i) b.push_back(lcm / i);
    }
    sort(all(b));
    if (a == b) {
        cout << lcm << "\n";
    } else {
        cout << "-1\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();   
}