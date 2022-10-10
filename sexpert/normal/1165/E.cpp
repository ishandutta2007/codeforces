#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const ll MOD = 998244353;
 
int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    for(ll i = 1; i <= n; i++) {
        a[i - 1] *= i;
        a[i - 1] *= ((ll)n + 1 - i);
    }
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans = (ans + ((a[i] % MOD) * b[i])) % MOD;
    }
    cout << ans << endl;
}