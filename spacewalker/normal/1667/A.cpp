#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll INF = 1e18;

// assumes n positive
ll strictNextMultiple(ll n, ll d) {
    return n + d - (n % d);
}

int main() {
    int n; scanf("%d", &n);
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    ll ans = INF;
    for (int center = 0; center < n; ++center) {
        ll cans = 0;
        vector<ll> b(n);
        for (int i = center - 1; i >= 0; --i) {
            b[i] = strictNextMultiple(b[i+1], a[i]); 
            cans += b[i] / a[i];
        }
        for (int i = center + 1; i < n; ++i) {
            b[i] = strictNextMultiple(b[i-1], a[i]);
            cans += b[i] / a[i];
        }
        ans = min(ans, cans);
        // printf("%d %lld\n", center, cans);
    }
    printf("%lld\n", ans);
}