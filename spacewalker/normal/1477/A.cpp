#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    a = abs(a), b = abs(b);
    if (b == 0) return a;
    else return gcd(b, a % b);
}

ll fmod(ll n, ll m) {
    return (n % m + m) % m;
}

bool solve() {
    int n; ll k; scanf("%d %lld", &n, &k);
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
    sort(begin(arr), end(arr));
    ll cdiv = 0;
    for (int i = 0; i + 1 < n; ++i) {
        cdiv = gcd(cdiv, arr[i+1] - arr[i]);
    }
    return fmod(k, cdiv) == fmod(arr[0], cdiv);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) printf("%s\n", solve() ? "YES": "NO");
    return 0;
}